#ifndef NOTIFICATIONTEXT_H
#define NOTIFICATIONTEXT_H

#include <QWidget>
#include <QLabel>

class NotificationText : public QWidget
{
    Q_OBJECT
private:
    QLabel* notificationText;
    QTimer* timer;
    std::string message;
    int currentIndex;
private slots:
    void updateText();
public:
    NotificationText(QWidget *parent = nullptr);
    void notify(const std::string& text);
};

#endif // NOTIFICATIONTEXT_H
