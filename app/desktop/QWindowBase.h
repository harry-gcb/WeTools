// #ifndef QWINDOWBASE_H
// #define QWINDOWBASE_H

// #include <QFrame>
// #include <QWidget>
// #include <QVBoxLayout>
// #include "TitleBar.h"

// /**
//  * @brief 界面组件基类
//  * @note QWindowBase界面组件主要用作顶层窗口，对于非顶层窗口的界面组件使用QWidget。
//  */
// class QWindowBase : public QFrame
// {
//     Q_OBJECT
// public:
//     QWindowBase(QFrame* parent = NULL);
//     /**
//      * @brief 设置标题
//      * @param title，输入参数，标题内容
//      */
//     void setWindowTitle(const QString& title);
//     /**
//      * @brief 设置标题栏的图标
//      * @param iconPath，输入参数，图标资源路径
//      */
//     void SetTitleBarIcon(const QString& iconPath);
//     /**
//      * @brief 获取内容组件对象指针
//      * @return 返回QWidget*
//      */
//     QWidget* contentWidget();
//     /**
//      * @brief 设置标题栏高度
//      * @param h，输入参数，标题栏高度
//      */
//     void setWindowTitleHeight(int h);

// private:
//     QWidget* m_contentWidget;//内容组件
//     TitleBar* m_titleBar;//标题栏
//     QVBoxLayout* m_layout;//布局管理器
// };

// #endif // QWINDOWBASE_H