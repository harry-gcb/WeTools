#ifndef QT_SIDEBAR_H_
#define QT_SIDEBAR_H_

#include "QtWidgets/QPushButton"
#include "QtWidgets/QVBoxLayout"
#include "qt_movewidget.h"
#include "qt_businesscard.h"

class Qt_SideBar: public Qt_MoveWidget {
    Q_OBJECT
public:
    explicit Qt_SideBar(QWidget *parent = Q_NULLPTR);

protected slots:
    void onBusinessCardShow();
private:
    Qt_BusinessCard *businessCardWidget_;
    QPushButton *businessCardButton_;
    QPushButton *messageButton_;
    QPushButton *contactButton_;
    QPushButton *redisButton_;
    QVBoxLayout *layout_;
};

#endif