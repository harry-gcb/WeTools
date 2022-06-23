#include "QtGui/QGuiApplication"
#include "qt_sidebar.h"

Qt_SideBar::Qt_SideBar(QWidget *parent): Qt_MoveWidget(parent) {
    businessCardWidget_ = new Qt_BusinessCard(this);

    businessCardButton_ = new QPushButton(this);
    businessCardButton_->setFixedSize(27, 27);
    businessCardButton_->setObjectName("Qt_SideBar::businessCardButton_");

    messageButton_ = new QPushButton(this);
    messageButton_->setFixedSize(27, 27);
    messageButton_->setObjectName("Qt_SideBar::messageButton_");

    contactButton_ = new QPushButton(this);
    contactButton_->setFixedSize(27, 27);
    contactButton_->setObjectName("Qt_SideBar::contactButton_");

    redisButton_ = new QPushButton(this);
    redisButton_->setFixedSize(27, 27);
    redisButton_->setObjectName("Qt_SideBar::redisButton_");

    layout_ = new QVBoxLayout;
    layout_->addWidget(businessCardButton_);
    layout_->addWidget(messageButton_);
    layout_->addWidget(contactButton_);
    layout_->addWidget(redisButton_);
    layout_->addStretch();
    setLayout(layout_);

    connect(businessCardButton_, SIGNAL(clicked(bool)), this, SLOT(onBusinessCardShow()));
}

void Qt_SideBar::onBusinessCardShow() {
    QScreen *screen = QGuiApplication::primaryScreen();
    QPoint globalPos = QCursor::pos(screen);
    businessCardWidget_->move(globalPos.x(), globalPos.y());
    businessCardWidget_->show();
}