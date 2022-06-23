#include "qt_movewidget.h"
#include "QtGui/QMouseEvent"

Qt_MoveWidget::Qt_MoveWidget(QWidget *parent): QWidget(parent) {}

void Qt_MoveWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QWidget *pWindow = this->window();
    if (!pWindow || !pWindow->isTopLevel()) {
        return;
    }
    pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
}

void Qt_MoveWidget::mousePressEvent(QMouseEvent *event)
{
    // 鼠标左键按下事件
    if (event->button() == Qt::LeftButton)
    {
        // 记录鼠标左键状态
        leftButtonPressed_ = true;
        //记录鼠标在屏幕中的位置
        start_ = event->globalPos();
    }
}

void Qt_MoveWidget::mouseMoveEvent(QMouseEvent *event)
{
    // 持续按住才做对应事件
    if(leftButtonPressed_)
    {
        //将父窗体移动到父窗体原来的位置加上鼠标移动的位置：event->globalPos()-m_start
        parentWidget()->move(parentWidget()->geometry().topLeft() +
                             event->globalPos() - start_);
        //将鼠标在屏幕中的位置替换为新的位置
        start_ = event->globalPos();
    }
}

void Qt_MoveWidget::mouseReleaseEvent(QMouseEvent *event)
{
    // 鼠标左键释放
    if (event->button() == Qt::LeftButton)
    {
        // 记录鼠标状态
        leftButtonPressed_ = false;
    }
}