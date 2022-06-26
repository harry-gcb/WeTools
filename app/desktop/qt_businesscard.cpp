#include "qt_businesscard.h"
#include "qt_common.h"

Qt_BusinessCard::Qt_BusinessCard(QWidget *parent): QWidget(parent) {
    setWindowFlags(Qt::Popup);
    setFixedSize(BUSINESSCARD_WIDGET_WIDTH, BUSINESSCARD_WIDGET_HEIGHT);

    avatar_ = new QLabel(this);
    avatar_->setObjectName(BUSINESSCARD_AVATAR_OBJNAME);
    avatar_->setText(QString("头像"));

    nickName_ = new QLabel(this);
    nickName_->setObjectName(BUSINESSCARD_NICKNAME_OBJNAME);
    nickName_->setText(QString("江湖渔民"));

    gender_ = new QLabel(this);
    gender_->setObjectName(BUSINESSCARD_GENDER_OBJNAME);
    gender_->setText(QString("test"));

    numberInfo_ = new QLabel(this);
    numberInfo_->setObjectName(BUSINESSCARD_NUMBERINFO_OBJNAME);
    numberInfo_->setText(QString("微信号：harry.gao"));

    areaInfo_ = new QLabel(this);
    areaInfo_->setObjectName(BUSINESSCARD_AREAINFO_OBJNAME);
    areaInfo_->setText(QString("地区：浙江 杭州"));

    introLayout_ = new QGridLayout;
    introLayout_->addWidget(avatar_, 0, 0, 3, 3);
    introLayout_->addWidget(nickName_, 0, 3);
    introLayout_->addWidget(gender_, 0, 4);
    introLayout_->addWidget(numberInfo_, 1, 3);
    introLayout_->addWidget(areaInfo_, 2, 3);

    sendMessageButton_ = new QPushButton(this);
    sendMessageButton_->setObjectName(BUSINESSCARD_SENDMESSAGE_OBJNAME);

    widgetLayout_ = new QVBoxLayout;
    widgetLayout_->addLayout(introLayout_, 1);
    widgetLayout_->addWidget(sendMessageButton_, 1);
    setLayout(widgetLayout_);

    // connect(nickName_, SIGNAL(textEdited(const QString &text)), this, SLOT(onNickNameChanged(const QString &text)));
}