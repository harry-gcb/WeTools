#include <QtWidgets/QApplication>
#include "qt_desktop.h"

#undef main
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Qt_Desktop desktop;
    desktop.show();
    return app.exec();
}

// #include <QApplication>
// #include "CommonHelper.h"
// #include "QWindowBase.h"
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QTreeView>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     QWindowBase w;
//     w.setWindowTitle("WidgetBase");
//     QPushButton* button1 = new QPushButton("OK");
//     QHBoxLayout* hLayout1 = new QHBoxLayout;
//     hLayout1->addStretch(1);
//     hLayout1->addWidget(button1);

//     QVBoxLayout* layout = new QVBoxLayout;
//     QTreeView* treeView = new QTreeView;
//     layout->addWidget(treeView);
//     layout->addLayout(hLayout1);
//     layout->addStretch(1);
//     w.contentWidget()->setLayout(layout);
//     w.setWindowTitleHeight(40);
//     w.show();
//     // CommonHelper::setStyleSheet("://qss/lightblue.qss");
//     return a.exec();
// }
