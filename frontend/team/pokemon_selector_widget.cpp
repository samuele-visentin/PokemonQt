#include "pokemon_selector_widget.h"
#include "backend/pokemons/charizard.h"
#include "backend/pokemons/darkrai.h"
#include "backend/pokemons/giratina.h"
#include "backend/pokemons/infernape.h"
#include "backend/pokemons/pikachu.h"
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>

PokemonSelectorWidget::PokemonSelectorWidget(QWidget *parent)
    : QWidget{parent}, _indexPokemon(PokemonTypology::typology::infernape)
{
    QHBoxLayout* row = new QHBoxLayout(this);
    _grid = new QGridLayout();
    _grid->setVerticalSpacing(10);
    QLabel* selectPokemonLabel = new QLabel("Seleziona il pokemon: ", this);
    _grid->addWidget(selectPokemonLabel, 0, 0);
    _selectPokemon = new QComboBox(this);
    std::vector<const PokemonTypology*> vec = PokemonTypology::getAllTypology();
    for(int index=0; index < static_cast<int>(vec.size()); ++index) {
        _selectPokemon->addItem(QString::fromStdString(vec[index]->getName()));
    }
    connect(_selectPokemon, &QComboBox::currentIndexChanged, this, &PokemonSelectorWidget::onSelectPokemon);
    _grid->addWidget(_selectPokemon, 0, 1);
    _spinBoxHealth = new QSpinBox(this);
    _spinBoxHealth->setMinimum(10);
    _spinBoxHealth->setMaximum(90000);
    _spinBoxHealth->setValue(250);
    QLabel* health = new QLabel("Quantita vita: ", this);
    _grid->addWidget(health,1,0);
    _grid->addWidget(_spinBoxHealth, 1,1);
    _spinBoxAttack = new QSpinBox(this);
    _spinBoxAttack->setRange(1, 10000);
    QLabel* attack = new QLabel("Quantita attacco: ", this);
    _grid->addWidget(attack, 2, 0);
    _grid->addWidget(_spinBoxAttack, 2,1);
    _spinBoxDefend = new QSpinBox(this);
    _spinBoxDefend->setRange(1,10000);
    QLabel* defense = new QLabel("Quantita difesa: ", this);
    _grid->addWidget(defense, 3, 0);
    _grid->addWidget(_spinBoxDefend, 3, 1);
    _spinBoxSpeed = new QSpinBox(this);
    _spinBoxSpeed->setRange(1,10000);
    QLabel* speed = new QLabel("Quantita velocità: ", this);
    _grid->addWidget(speed, 4, 0);
    _grid->addWidget(_spinBoxSpeed, 4, 1);
    QLabel* name = new QLabel("Nome del pokemon: ", this);
    _grid->addWidget(name, 5, 0);
    _name = new QLineEdit(this);
    _name->setText("Infernape");
    _grid->addWidget(_name, 5, 1);
    row->addLayout(_grid);
    _image = new QLabel(this);
    QPixmap pixmap(QString::fromStdString(PokemonTypology::infernape.getSprite()));
    pixmap.scaled(80,80,Qt::KeepAspectRatio);
    _image->setPixmap(pixmap);
    _image->setFixedHeight(80);
    row->setSpacing(30);
    row->setAlignment(Qt::AlignCenter);
    row->addWidget(_image);
}

void PokemonSelectorWidget::onSelectPokemon(int index) {
    _indexPokemon = PokemonTypology::typology(index);
    for (const PokemonTypology* t: PokemonTypology::getAllTypology()) {
        if(t->getTypology() == _indexPokemon) {
            _name->setText(QString::fromStdString(t->getName()));
            QPixmap pixmap(QString::fromStdString(t->getSprite()));
            pixmap.scaled(80,80,Qt::KeepAspectRatio);
            _image->setPixmap(pixmap);
            return;
        }
    }
}

Pokemon* PokemonSelectorWidget::getPokemon() const {
    std::string name = _name->text().toStdString();
    int health = _spinBoxHealth->value();
    int attack = _spinBoxAttack->value();
    int defense = _spinBoxDefend->value();
    int speed = _spinBoxSpeed->value();
    switch(_indexPokemon) {
        case PokemonTypology::typology::infernape:
            return new Infernape(health, attack, defense, speed, name);
        case PokemonTypology::typology::charizard:
            return new Charizard(health, attack, defense, speed, name);
        case PokemonTypology::typology::giratina:
            return new Giratina(health, attack, defense, speed, name);
        case PokemonTypology::typology::darkrai:
            return new Darkrai(health, attack, defense, speed, name);
        case PokemonTypology::typology::pikachu:
            return new Pikachu(health, attack, defense, speed, name);
        default:
            throw "Wrong index";
    }
}

void PokemonSelectorWidget::refresh(const Pokemon& pokemon) {
    _name->setText(QString::fromStdString(pokemon.getName()));
    _spinBoxHealth->setValue(pokemon.getHealth());
    _spinBoxAttack->setValue(pokemon.getAttack());
    _spinBoxDefend->setValue(pokemon.getDefense());
    _spinBoxSpeed->setValue(pokemon.getSpeed());
    _selectPokemon->setCurrentIndex(static_cast<int>(pokemon.getTypology()));
    QPixmap pixmap(QString::fromStdString(":assets/pokemons/front/"+pokemon.getSprite()));
    pixmap.scaled(80,80,Qt::KeepAspectRatio);
    _image->setPixmap(pixmap);
}
