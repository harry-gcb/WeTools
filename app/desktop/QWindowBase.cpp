// #include "QWindowBase.h"

// QWindowBase::QWindowBase(QFrame *parent): QFrame(parent)
// {
//     setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
//     m_titleBar = new TitleBar(this);
//     m_contentWidget = new QWidget(this);
//     m_contentWidget->setObjectName("Contents");
//     m_layout = new QVBoxLayout;
//     m_layout->addWidget(m_titleBar);
//     m_layout->addWidget(m_contentWidget);
//     m_layout->setSpacing(0);
//     m_layout->setContentsMargins(0, 0, 0, 0);

//     setLayout(m_layout);
// }

// void QWindowBase::setWindowTitle(const QString &title)
// {
//     m_titleBar->setWindowTitle(title);
// }

// void QWindowBase::SetTitleBarIcon(const QString &iconPath)
// {
//     m_titleBar->SetTitleBarIcon(iconPath);
// }

// QWidget *QWindowBase::contentWidget()
// {
//     return m_contentWidget;
// }

// void QWindowBase::setWindowTitleHeight(int h)
// {
//     m_titleBar->setFixedHeight(h);
// }