#ifndef QT_DESKTOP_H_
#define QT_DESKTOP_H_

#include "QtWidgets/QWidget"
#include "QtWidgets/QHBoxLayout"

#include "qt_sidebar.h"
#include "qt_drawer.h"
#include "qt_content.h"

class Qt_Desktop : public QWidget {
    Q_OBJECT
public:
    explicit Qt_Desktop(QWidget *parent = Q_NULLPTR);

private:
    Qt_SideBar  *sideBar_; // 侧边栏
    Qt_Drawer   *drawer_;  // 中间的信息列表
    Qt_Content  *content_; // 内容窗口
    QHBoxLayout *layout_;  // 布局管理器
};

#endif