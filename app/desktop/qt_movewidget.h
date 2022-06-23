#ifndef QT_MOVEWIDGET_H_
#define QT_MOVEWIDGET_H_

#include "QtWidgets/QWidget"

class Qt_MoveWidget : public QWidget {
    Q_OBJECT
public:
    explicit Qt_MoveWidget(QWidget *parent = Q_NULLPTR);

protected:
    /**
     * @brief 鼠标双击事件处理函数
     * @param event，参数，事件
     * @note 双击标题栏进行界面的最大化/还原
     */
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

    /**
     * @brief 鼠标按下事件处理函数
     * @param event，参数，事件
     * @note 按下鼠标左键
     */
    virtual void mousePressEvent(QMouseEvent *event);
    /**
     * @brief 鼠标移动事件处理函数
     * @param event，参数，事件
     * @note 移动鼠标
     */
    virtual void mouseMoveEvent(QMouseEvent *event);
    /**
     * @brief 鼠标释放事件处理函数
     * @param event，参数，事件
     * @note 释放鼠标
     */
    virtual void mouseReleaseEvent(QMouseEvent *event);

    /**
     * @brief 事件过滤处理器
     * @param obj，参数
     * @param event，参数，事件
     * @return 成功返回true，失败返回false
     * @note 设置标题、图标
     */
    // virtual bool eventFilter(QObject *obj, QEvent *event);

    /**
     * @brief 最大化/还原
     */
    // void updateMaximize();
private:
    QPoint start_;           //起始点
    QPoint end_;             //结束点
    bool leftButtonPressed_; //鼠标左键按下标记
};

#endif