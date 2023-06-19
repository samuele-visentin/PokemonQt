#ifndef NOTIFICATIONTEXT_H
#define NOTIFICATIONTEXT_H

#include <QWidget>
#include <QLabel>
#include <QEventLoop>

class NotificationText : public QWidget
{
    Q_OBJECT
private:
    QLabel* notificationText;
public:
    NotificationText(QWidget *parent = nullptr);
    void notify(const std::string& text);
};

#endif // NOTIFICATIONTEXT_H
