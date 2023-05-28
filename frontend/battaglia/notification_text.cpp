#include "notification_text.h"
#include <QTimer>
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
    timer = new QTimer(this);
    timer->setInterval(25);
    connect(timer, &QTimer::timeout, this, &NotificationText::updateText);
}

void NotificationText::updateText() {
    if (currentIndex < static_cast<int>(message.length())) {
        notificationText->setText(QString::fromStdString(message).left(++currentIndex));
    } else {
        timer->stop();
    }
}

void NotificationText::notify(const std::string& text) {
    message = text;
    currentIndex = 0;
    notificationText->setText("");
    timer->start();
}
