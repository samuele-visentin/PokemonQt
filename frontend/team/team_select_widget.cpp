#include "team_select_widget.h"
#include "frontend/team/pokemon_selector_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QAction>

TeamSelectWidget::TeamSelectWidget(QWidget *parent)
    : QWidget{parent}, numberPokemon(0)
{
    QHBoxLayout* primaryRow = new QHBoxLayout(this);
    QVBoxLayout* primaryColumn = new QVBoxLayout();
    QHBoxLayout* buttonRow = new QHBoxLayout();
    QHBoxLayout* saveRow = new QHBoxLayout();
    QHBoxLayout* searchRow = new QHBoxLayout();
    QPushButton* exitButton = new QPushButton("Ritorna al menu", this);
    exitButton->setFixedWidth(150);
    _fileName = new QLineEdit(this);
    QLabel* saveLabel = new QLabel("Nome del file: ", this);
    _saveButton = new QPushButton("Salva su file", this);
    QLabel* searchLabel = new QLabel("Nome del pokemon da cercare: ", this);
    _nameToSearch = new QLineEdit("Nome pokemon", this);
    _searchButton = new QPushButton("Cerca pokemon", this);
    _addButton = new QPushButton("Aggiugni", this);
    _modifyButton = new QPushButton("Modifica", this);
    _modifyButton->setEnabled(false);
    _removeButton = new QPushButton("Rimuovi", this);
    _removeButton->setEnabled(false);
    _selector = new PokemonSelectorWidget(this);
    primaryRow->addStretch(1);
    primaryRow->addLayout(primaryColumn);
    primaryRow->addStretch(1);
    primaryColumn->addStretch(1);
    saveRow->addWidget(saveLabel);
    saveRow->addSpacing(10);
    saveRow->addWidget(_fileName);
    saveRow->addStretch(1);
    saveRow->addWidget(_saveButton);
    primaryColumn->addWidget(exitButton, 0, Qt::AlignRight);
    primaryColumn->addSpacing(30);
    primaryColumn->addLayout(saveRow);
    searchRow->addWidget(searchLabel);
    searchRow->addStretch(1);
    searchRow->addWidget(_nameToSearch);
    searchRow->addStretch(1);
    searchRow->addWidget(_searchButton);
    primaryColumn->addLayout(searchRow);
    primaryColumn->addWidget(_selector);
    buttonRow->addWidget(_addButton);
    buttonRow->addWidget(_modifyButton);
    buttonRow->addWidget(_removeButton);
    primaryColumn->addLayout(buttonRow);
    primaryColumn->addStretch(1);

    //Definiamo lo shortcut per salvare
    QAction* saveAction = new QAction("Save", this);
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction, &QAction::triggered, this, &TeamSelectWidget::saveFile);
    this->addAction(saveAction);
    QAction* backAction = new QAction("Back",this);
    backAction->setShortcut(QKeySequence::fromString("Ctrl+B"));
    connect(backAction, &QAction::triggered, this, &TeamSelectWidget::returnToMain);
    this->addAction(backAction);

    connect(exitButton, &QPushButton::clicked, this, &TeamSelectWidget::returnToMain);
    connect(_saveButton, &QPushButton::clicked, this, &TeamSelectWidget::saveFile);
    connect(_searchButton, &QPushButton::clicked, this, &TeamSelectWidget::findPokemon);
    connect(_addButton, &QPushButton::clicked, this, &TeamSelectWidget::addPokemon);
    connect(_modifyButton, &QPushButton::clicked, this, &TeamSelectWidget::modifyPokemon);
    connect(_removeButton, &QPushButton::clicked, this, &TeamSelectWidget::removePokemon);
}

TeamSelectWidget::~TeamSelectWidget() {
    for (auto it=_pokemonList.begin(); it != _pokemonList.end(); ++it) {
        delete *it;
    }
}

void TeamSelectWidget::setFile(const std::string& fileName) {
    for (auto it=_pokemonList.begin(); it != _pokemonList.end(); ++it) {
        delete *it;
    }
    _pokemonList.erase();
    numberPokemon = 0;
    if(fileName != "") {
        QFile file(QString::fromStdString(fileName));
        if(file.open(QIODevice::ReadOnly)) {
            QDataStream in (&file);
            in.setVersion(QDataStream::Qt_6_2);
            while (!in.atEnd()) {
                Pokemon* p = nullptr;
                in >> p;
                _pokemonList.insertBack(p);
                ++numberPokemon;
            }
            file.close();
        } else {
            QMessageBox::information(this, "Error", "Impossibile aprire il file");
        }
        _fileName->setText(QString::fromStdString(fileName));
    } else {
        _fileName->setText("Nome file");
    }
}

void TeamSelectWidget::addPokemon()
{
    if(numberPokemon >= 6){
        QMessageBox::information(this, "Pokemon", "Hai aggiunto già sei pokemon!");
        return;
    }
    ++numberPokemon;
    _pokemonList.insertBack(_selector->getPokemon());
    QMessageBox::information(this, "Pokemon", "Pokemon aggiunto");
    if(_modifyButton->isEnabled())
        _modifyButton->setEnabled(false);
    if(_removeButton->isEnabled())
        _removeButton->setEnabled(false);
}

void TeamSelectWidget::modifyPokemon()
{
    _pokemonList.insert(_iterator, _selector->getPokemon());
    _pokemonList.removeAt(++_iterator);
    QMessageBox::information(this, "Pokemon", "Pokemon modificato");
    _modifyButton->setEnabled(false);
    _removeButton->setEnabled(false);
}

void TeamSelectWidget::removePokemon()
{
    --numberPokemon;
    Pokemon* p = _pokemonList.removeAt(_iterator);
    delete p;
    QMessageBox::information(this, "Pokemon", "Pokemon eliminato");
    _modifyButton->setEnabled(false);
    _removeButton->setEnabled(false);
}

bool pokemonEqual(Pokemon* p, const std::string& name) {
    return p->getName()==name;
}

void TeamSelectWidget::findPokemon() {
    _iterator = _pokemonList.find(_nameToSearch->text().toStdString(), pokemonEqual);
    if(_iterator != _pokemonList.end()) {
        _selector->refresh(**_iterator);
        QMessageBox::information(this, "Risulato", "Pokemon trovato.");
        if(!_modifyButton->isEnabled())
            _modifyButton->setEnabled(true);
        if(!_removeButton->isEnabled())
            _removeButton->setEnabled(true);
    } else {
        QMessageBox::information(this, "Risultato", "Pokemon non trovato");
        if(_modifyButton->isEnabled())
            _modifyButton->setEnabled(false);
        if(_removeButton->isEnabled())
            _removeButton->setEnabled(false);
    }
}

void TeamSelectWidget::saveFile() {
    QFile file(_fileName->text()+".pokemon");
    if(file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_6_2);
        for (auto it = _pokemonList.begin(); it != _pokemonList.end(); ++it) {
            out << **it;
        }
        file.close();
        QMessageBox::information(this, "Pokemon", "File salvato!");
    } else {
        QMessageBox::information(this, "Pokemon", "File NON salvato!");
    }
}

