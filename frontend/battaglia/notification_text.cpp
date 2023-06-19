#include "notification_text.h"
#include <QThread>
#include <QCoreApplication>
#include <QHBoxLayout>

NotificationText::NotificationText(QWidget *parent)
    : QWidget{parent}
{
    QHBoxLayout* row = new QHBoxLayout(this);
    notificationText = new QLabel(this);
    notificationText->setFixedSize(600,60);
    notificationText->setAlignment(Qt::AlignTop);
    notificationText->setStyleSheet("QLabel {"
                                    "background-color: white;"
                                    "border-radius: 5px;"
                                    "margin: 10px;"
                                    "}");
    row->addWidget(notificationText);
}

void NotificationText::notify(const std::string& text) {
    notificationText->setText("");
    for(int index=0; index<=static_cast<int>(text.length()); ++index) {
        notificationText->setText(QString::fromStdString(text).left(index));
        QCoreApplication::processEvents();
        QThread::msleep(15);
    }
    //Diamo un tempo breve per leggere
    QThread::msleep(500);
}

