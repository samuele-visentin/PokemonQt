#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "frontend/battaglia/battle_scene.h"
#include "frontend/team/team_select_widget.h"
#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLineEdit* _playerName;
    QLineEdit* _enemyName;
    QStackedWidget* _stackWidget;
    QLineEdit* _fileName;
    QPushButton* _pickFile;
    QPushButton* _play;
    QPushButton* _team;
    BattleScene* _battleScene;
    TeamSelectWidget* _teamScene;
    void centerWindow();
private slots:
    void onPlayButton();
    void onTeamButton();
    void showMenu();
    void selectFile();
public:
    MainWindow(QWidget *parent = nullptr);
};
#endif // MAINWINDOW_H
