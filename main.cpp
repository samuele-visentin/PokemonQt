#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QIcon icon(":assets/masterball.ico");
    app.setWindowIcon(icon);
    MainWindow w;
    w.show();
    return app.exec();
}
