#include "mainwindow.h"
#include "backend/battle/battle.h"
#include "frontend/battaglia/battle_scene.h"
#include "backend/pokemons/charizard.h"
#include <QApplication>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Qt Pokemon");
    setFixedSize(300,180);

    _title = new QLabel();
    _title->setText("<b>Pokemon simulator battle</b>");
    _title->setAlignment(Qt::AlignCenter);

    _text = new QLabel();
    _text->setText("Seleziona il team da usare:");

    _dropdown = new QComboBox();
    _dropdown->addItem("Default team");
    _dropdown->addItem("Custom team");

    _play = new QPushButton("Play");
    _play->setMaximumSize(100,30);
    _team = new QPushButton("Creazione team");
    _team->setMaximumSize(100,30);

    _buttonLayout = new QHBoxLayout();
    _buttonLayout->addWidget(_play);
    _buttonLayout->addWidget(_team);

    _layout = new QVBoxLayout();
    _layout->addWidget(_title);
    _layout->addSpacing(10);
    _layout->addWidget(_text);
    _layout->addWidget(_dropdown);
    _layout->addLayout(_buttonLayout);
    _layout->setAlignment(Qt::AlignCenter);

    _centralWidget = new QWidget();
    _centralWidget->setLayout(_layout);
    setCentralWidget(_centralWidget);

    connect(_play, &QPushButton::clicked, this, &MainWindow::onPlayButton);
    connect(_team, &QPushButton::clicked, this, &MainWindow::onTeamButton);
}

void MainWindow::onPlayButton(){
    //TODO load from json ->
    std::list<Pokemon*> list1, list2;
    std::vector<Attack> attack;
    attack.push_back(Attack::AIR_SLASH);
    attack.push_back(Attack::BITE);
    attack.push_back(Attack::QUICK_ATTACK);
    attack.push_back(Attack::DARK_PULSE);
    list1.push_front(new Charizard(100,100,100,100, 50,attack));
    list2.push_front(new Charizard(100,100,100,100, 50,attack));
    Player player("SUS",list1);
    Enemy enemy("SAS",list2);
    Battle battle(player, enemy);
    _battleScene = new BattleScene(battle);
    // <-

    setFixedSize(1000,600);
    //Portiamo la schermata al centro dello schermo
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect availableGeometry = screen->availableGeometry();
    int x = (availableGeometry.width() - width()) / 2;
    int y = (availableGeometry.height() - height()) / 2;
    move(x, y);
    setCentralWidget(_battleScene);
}
void MainWindow::onTeamButton(){
    //TODO creazione team
}

