#include "qt_desktop.h"

Qt_Desktop::Qt_Desktop(QWidget *parent)
    : QWidget(parent) {
    setMinimumSize(800, 600);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    sideBar_ = new Qt_SideBar(this);
    sideBar_->setObjectName("Qt_SideBar");
    drawer_ = new Qt_Drawer(this);
    drawer_->setObjectName("Qt_Drawer");
    content_ = new Qt_Content(this);
    content_->setObjectName("Qt_Content");

    layout_ = new QHBoxLayout;
    layout_->addWidget(sideBar_);
    layout_->addWidget(drawer_);
    layout_->addWidget(content_);
    layout_->setSpacing(0);
    layout_->setContentsMargins(0, 0, 0, 0);
    setLayout(layout_);
}