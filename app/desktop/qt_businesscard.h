#ifndef QT_BUSINESS_CARD_H_
#define QT_BUSINESS_CARD_H_

#include "QtWidgets/QWidget"
#include "QtWidgets/QLabel"
#include "QtWidgets/QGridLayout"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QVBoxLayout"


class Qt_BusinessCard: public QWidget {
    Q_OBJECT
public:
    explicit Qt_BusinessCard(QWidget *parent = Q_NULLPTR);

private:
    QLabel *avatar_;
    QLabel *nickName_;
    QLabel *gender_;
    QLabel *numberInfo_;
    QLabel *areaInfo_;
    QGridLayout *introLayout_;

    QPushButton *sendMessageButton_;
    
    QVBoxLayout *widgetLayout_;

};

#endif