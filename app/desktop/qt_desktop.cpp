#include "qt_desktop.h"
#include "qt_common.h"

// 桌面窗口配置
#define DESKTOP_WIDGET_WIDTH 1000
#define DESKTOP_WIDGET_HEIGHT 618
#define DESKTOP_SIDEBAR_OBJNAME "Desktop_sidebar_"
#define DESKTOP_DRAWER_OBJNAME "Desktop_drawer_"
#define DESKTOP_CONTENT_OBJNAME "Desktop_content_"

#define DESKTOP_SIDEBAR_WIDGET_FIXED_WIDTH 82
#define DESKTOP_DRAWER_WIDGET_FIXED_WIDTH 300
#define DESKTOP_CONTENT_WIDGET_MIN_WIDTH 618

Qt_Desktop::Qt_Desktop(QWidget *parent)
    : QWidget(parent) {
    setMinimumSize(DESKTOP_WIDGET_WIDTH, DESKTOP_WIDGET_HEIGHT);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    sideBar_ = new Qt_SideBar(this);
    sideBar_->setObjectName(DESKTOP_SIDEBAR_OBJNAME);
    sideBar_->setFixedWidth(DESKTOP_SIDEBAR_WIDGET_FIXED_WIDTH);

    drawer_ = new Qt_Drawer(this);
    drawer_->setObjectName(DESKTOP_DRAWER_OBJNAME);
    drawer_->setFixedWidth(DESKTOP_DRAWER_WIDGET_FIXED_WIDTH);

    content_ = new Qt_Content(this);
    content_->setObjectName(DESKTOP_CONTENT_OBJNAME);
    content_->setMinimumWidth(DESKTOP_CONTENT_WIDGET_MIN_WIDTH);

    layout_ = new QHBoxLayout;
    layout_->addWidget(sideBar_);
    layout_->addWidget(drawer_);
    layout_->addWidget(content_);
    layout_->setSpacing(0);
    layout_->setContentsMargins(0, 0, 0, 0);
    setLayout(layout_);
}