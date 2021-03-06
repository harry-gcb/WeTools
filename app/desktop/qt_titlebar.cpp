// #include "qt_titlebar.h"

// Qt_TitleBar::Qt_TitleBar(QWidget *parent) : QWidget(parent)
// {
//     setFixedHeight(30);
//     setWindowFlags(Qt::FramelessWindowHint);
//     m_iconLabel = new QLabel(this);
//     m_iconLabel->setFixedSize(20, 20);
//     m_iconLabel->setScaledContents(true);

//     m_titleLabel = new QLabel(this);
//     m_titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

//     m_minimizeButton = new QPushButton(this);
//     m_minimizeButton->setFixedSize(27, 22);
//     m_minimizeButton->setObjectName("minimizeButton");

//     m_maximizeButton = new QPushButton(this);
//     m_maximizeButton->setFixedSize(27, 22);
//     m_maximizeButton->setObjectName("maximizeButton");

//     m_closeButton = new QPushButton(this);
//     m_closeButton->setFixedSize(27, 22);
//     m_closeButton->setObjectName("closeButton");

//     QHBoxLayout* layout = new QHBoxLayout;
//     layout->addWidget(m_iconLabel);
//     layout->addStretch(1);
//     layout->addWidget(m_titleLabel);
//     layout->addStretch(1);
//     layout->addWidget(m_minimizeButton);
//     layout->addWidget(m_maximizeButton);
//     layout->addWidget(m_closeButton);
//     setLayout(layout);

//     setProperty("titleBar", true);
//     setObjectName("titleBar");

//     connect(m_minimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
//     connect(m_maximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
//     connect(m_closeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
// }

// void Qt_TitleBar::setWindowTitle(const QString &title)
// {
//     m_titleLabel->setAlignment(Qt::AlignCenter);
//     m_titleLabel->setText(title);
// }

// void Qt_TitleBar::setTitleBarIcon(const QString &iconPath)
// {
//     QPixmap map(iconPath);
//     m_iconLabel->setPixmap(map);
// }

// void Qt_TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
// {
//     m_maximizeButton->click();
// }

// void Qt_TitleBar::mousePressEvent(QMouseEvent *event)
// {
//     // ????????????????????????
//     if (event->button() == Qt::LeftButton)
//     {
//         // ????????????????????????
//         m_leftButtonPressed = true;
//         //?????????????????????????????????
//         m_start = event->globalPos();
//     }

// }

// void Qt_TitleBar::mouseMoveEvent(QMouseEvent *event)
// {
//     // ??????????????????????????????
//     if(m_leftButtonPressed)
//     {
//         //???????????????????????????????????????????????????????????????????????????event->globalPos()-m_start
//         parentWidget()->move(parentWidget()->geometry().topLeft() +
//                              event->globalPos() - m_start);
//         //???????????????????????????????????????????????????
//         m_start = event->globalPos();
//     }

// }

// void Qt_TitleBar::mouseReleaseEvent(QMouseEvent *event)
// {
//     // ??????????????????
//     if (event->button() == Qt::LeftButton)
//     {
//         // ??????????????????
//         m_leftButtonPressed = false;
//     }
// }

// bool Qt_TitleBar::eventFilter(QObject *obj, QEvent *event)
// {
//     switch(event->type())
//     {
//     //????????????
//     case QEvent::WindowTitleChange:
//     {
//         QWidget *pWidget = qobject_cast<QWidget *>(obj);
//         if (pWidget)
//         {
//             m_titleLabel->setText(pWidget->windowTitle());
//             return true;
//         }
//     }
//     //????????????
//     case QEvent::WindowIconChange:
//     {
//         QWidget *pWidget = qobject_cast<QWidget *>(obj);
//         if (pWidget)
//         {
//             QIcon icon = pWidget->windowIcon();
//             m_iconLabel->setPixmap(icon.pixmap(m_iconLabel->size()));
//             return true;
//         }
//     }
//     // ???????????????????????????????????????
//     case QEvent::WindowStateChange:
//     case QEvent::Resize:
//         updateMaximize();
//         return true;
//     }
//     return QWidget::eventFilter(obj, event);
// }

// void Qt_TitleBar::updateMaximize()
// {
//     QWidget *pWindow = this->window();
//     if (pWindow->isTopLevel())
//     {
//         bool bMaximize = pWindow->isMaximized();
//         if (bMaximize)
//         {
//             m_maximizeButton->setToolTip(tr("Restore"));
//             m_maximizeButton->setProperty("maximizeProperty", "restore");
//         }
//         else
//         {
//             m_maximizeButton->setProperty("maximizeProperty", "maximize");
//             m_maximizeButton->setToolTip(tr("Maximize"));
//         }

//         m_maximizeButton->setStyle(QApplication::style());
//     }
// }

// void Qt_TitleBar::onClicked()
// {
//     QPushButton *pButton = qobject_cast<QPushButton *>(sender());
//     QWidget *pWindow = this->window();
//     if (pWindow->isTopLevel())
//     {
//         if (pButton == m_minimizeButton)
//         {
//             pWindow->showMinimized();
//         }
//         else if (pButton == m_maximizeButton)
//         {
//             pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
//         }
//         else if (pButton == m_closeButton)
//         {
//             pWindow->close();
//         }
//     }
// }