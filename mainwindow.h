#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel* _title;
    QLabel* _text;
    QComboBox* _dropdown;
    QPushButton* _play;
    QPushButton* _team;
    QVBoxLayout* _layout;
    QWidget* _centralWidget;
    QHBoxLayout* _buttonLayout;
private slots:
    void onPlayButton();
    void onTeamButton();
public:
    MainWindow(QWidget *parent = nullptr);
};
#endif // MAINWINDOW_H
