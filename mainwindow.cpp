#include "mainwindow.h"
#include "backend/battle/battle.h"
#include "frontend/battaglia/battle_scene.h"
#include <QApplication>
#include <QScreen>
#include <QStackedWidget>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), _battleScene(nullptr)
{
    setWindowTitle("Qt Pokemon");
    setFixedSize(500,400);

    _stackWidget = new QStackedWidget(this);
    QPixmap pixmap(":assets/masterball.ico");
    QLabel* logo = new QLabel(this);
    logo->setPixmap(pixmap.scaled(30,30,Qt::KeepAspectRatio));
    logo->setAlignment(Qt::AlignCenter);

    QLabel* _title = new QLabel(this);
    _title->setText("<b>Pokemon simulator battle</b>");
    _title->setAlignment(Qt::AlignCenter); 

    QLabel* _text = new QLabel(this);
    _text->setText("Seleziona il file da cui caricare il tuo team:");
    _text->setAlignment(Qt::AlignCenter);

    _dropdown = new QComboBox(this);
    _dropdown->setFixedWidth(150);
    refreshSaved();

    _play = new QPushButton("Play", this);
    _play->setFixedWidth(120);

    _team = new QPushButton("Creazione team", this);
    _team->setFixedWidth(120);

    QHBoxLayout* _buttonLayout = new QHBoxLayout();
    _buttonLayout->addWidget(_play);
    _buttonLayout->addWidget(_team);

    QHBoxLayout* playerRow = new QHBoxLayout();
    QLabel* _playerNameLabel = new QLabel("Il tuo nickname: ", this);
    _playerName = new QLineEdit("Player", this);
    playerRow->addStretch(1);
    playerRow->addWidget(_playerNameLabel);
    playerRow->addSpacing(20);
    playerRow->addWidget(_playerName);
    playerRow->addStretch(1);

    QHBoxLayout* enemyRow = new QHBoxLayout();
    QLabel* _enemyNameLabel = new QLabel("Il tuo avversario: ", this);
    _enemyName = new QLineEdit("Enemy", this);
    enemyRow->addStretch(1);
    enemyRow->addWidget(_enemyNameLabel);
    enemyRow->addSpacing(20);
    enemyRow->addWidget(_enemyName);
    enemyRow->addStretch(1);

    QVBoxLayout* _layout = new QVBoxLayout();
    _layout->setAlignment(Qt::AlignCenter);
    _layout->addWidget(logo);
    _layout->addSpacing(5);
    _layout->addWidget(_title);
    _layout->addSpacing(10);
    _layout->addLayout(playerRow);
    _layout->addLayout(enemyRow);
    _layout->addSpacing(10);
    _layout->addWidget(_text);
    _layout->addWidget(_dropdown);
    _layout->setAlignment(_dropdown, Qt::AlignCenter);
    _layout->addSpacing(10);
    _layout->addLayout(_buttonLayout);

    _teamScene = new TeamSelectWidget(this);

    QWidget* _centralWidget = new QWidget(this);
    _centralWidget->setLayout(_layout);
    _stackWidget->addWidget(_centralWidget);
    _stackWidget->addWidget(_teamScene);
    _stackWidget->setCurrentWidget(_centralWidget);
    setCentralWidget(_stackWidget);

    connect(_play, &QPushButton::clicked, this, &MainWindow::onPlayButton);
    connect(_team, &QPushButton::clicked, this, &MainWindow::onTeamButton); 
    connect(_teamScene, &TeamSelectWidget::returnToMain, this, &MainWindow::showMenu);
}

void MainWindow::centerWindow() {
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect availableGeometry = screen->availableGeometry();
    int x = (availableGeometry.width() - width()) / 2;
    int y = (availableGeometry.height() - height()) / 2;
    move(x, y);
}

void MainWindow::refreshSaved() {
    _dropdown->clear();
    QDir dir("./");
    QStringList filters;
    filters << "*.pokemon";
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Files | QDir::NoSymLinks);
    _dropdown->addItems(dir.entryList());
}

void MainWindow::onPlayButton(){
    if(_dropdown->currentText() == "") {
        QMessageBox::information(this, "Pokemon", "Nessun file valido");
        return;
    }
    std::vector<Pokemon*> playerList;
    QFile file(_dropdown->currentText());
    if(file.open((QIODevice::ReadOnly))) {
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_6_2);
        while(!in.atEnd()) {
            Pokemon* p = nullptr;
            in >> p;
            playerList.push_back(p);
        }
        file.close();
    } else {
        QMessageBox::information(this, "Pokemon", "Errore nell'apertura del file");
        return;
    }
    Player player(_playerName->text().toStdString(),playerList);
    Enemy enemy(_enemyName->text().toStdString());
    Battle battle(player, enemy);
    if(_battleScene) {
        _stackWidget->removeWidget(_battleScene);
        disconnect(_battleScene, &BattleScene::returnToMain, this, &MainWindow::showMenu);
        delete _battleScene;
    }
    _battleScene = new BattleScene(battle, this);
    connect(_battleScene, &BattleScene::returnToMain, this, &MainWindow::showMenu);
    setFixedSize(1000,600);
    centerWindow();
    _stackWidget->addWidget(_battleScene);
    _stackWidget->setCurrentWidget(_battleScene);
}

void MainWindow::onTeamButton(){
    _teamScene->setFile(_dropdown->currentText().toStdString());
    _stackWidget->setCurrentWidget(_teamScene);
    setFixedSize(600,450);
    centerWindow();
}

void MainWindow::showMenu() {
    _stackWidget->setCurrentIndex(0);
    setFixedSize(500,400);
    centerWindow();
    refreshSaved();
}
