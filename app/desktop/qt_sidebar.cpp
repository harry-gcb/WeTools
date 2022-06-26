#include "QtGui/QGuiApplication"
#include "qt_sidebar.h"
#include "qt_tools.h"

// sidebar控件配置
#define SIDEBAR_BTN_WIDTH 36
#define SIDEBAR_BTN_HEIGHT 36
#define SIDEBAR_BUSINESSCARD_BTN_OBJNAME "SideBar_businessCardButton_"
#define SIDEBAR_MESSAGE_BTN_OBJNAME "SideBar_messageButton_"
#define SIDEBAR_CONTACT_BTN_OBJNAME "SideBar_contactButton_"
#define SIDEBAR_REDIS_BTN_OBJNAME "SideBar_redisButton_"
// sidebar贴图
#define SIDEBAR_BUSINESSCARD_BTN_IMAGE ":/image/public/avatar.jpg"

Qt_SideBar::Qt_SideBar(QWidget *parent): Qt_MoveWidget(parent) {
    businessCardWidget_ = new Qt_BusinessCard(this);

    businessCardButton_ = new QPushButton(this);
    businessCardButton_->setFixedSize(SIDEBAR_BTN_WIDTH, SIDEBAR_BTN_HEIGHT);
    businessCardButton_->setObjectName(SIDEBAR_BUSINESSCARD_BTN_OBJNAME);
    Qt_Tools::getInstance()->setButtonPixmap(businessCardButton_, SIDEBAR_BUSINESSCARD_BTN_IMAGE);

    messageButton_ = new QPushButton(this);
    messageButton_->setFixedSize(SIDEBAR_BTN_WIDTH, SIDEBAR_BTN_HEIGHT);
    messageButton_->setObjectName(SIDEBAR_MESSAGE_BTN_OBJNAME);

    contactButton_ = new QPushButton(this);
    contactButton_->setFixedSize(SIDEBAR_BTN_WIDTH, SIDEBAR_BTN_HEIGHT);
    contactButton_->setObjectName(SIDEBAR_CONTACT_BTN_OBJNAME);

    redisButton_ = new QPushButton(this);
    redisButton_->setFixedSize(SIDEBAR_BTN_WIDTH, SIDEBAR_BTN_HEIGHT);
    redisButton_->setObjectName(SIDEBAR_REDIS_BTN_OBJNAME);

    buttonGroup_ = new QButtonGroup(this);
    buttonGroup_->addButton(businessCardButton_, 0);
    buttonGroup_->addButton(messageButton_, 1);
    buttonGroup_->addButton(contactButton_, 2);
    buttonGroup_->addButton(redisButton_, 3);
    buttonGroup_->setExclusive(true);

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