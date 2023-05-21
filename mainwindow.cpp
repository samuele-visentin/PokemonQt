#include "mainwindow.h"
#include "backend/battle/battle.h"
#include "frontend/battaglia/battle_scene.h"
#include "backend/pokemons/charizard.h"

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
    //TODO load from json
    std::list<Pokemon*> list1, list2;
    std::list<Attack*> attack;
    list1.push_front(new Charizard(100,100,100,100,20,20,50,attack));
    list2.push_front(new Charizard(100,100,100,100,20,20,50,attack));
    Battle battle(list1,list2,"Player1","Player2");
    _battleScene = new BattleScene(battle);
    setCentralWidget(_battleScene);
}
void MainWindow::onTeamButton(){
    //TODO creazione team
}

