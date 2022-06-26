#include "QtWidgets/QApplication"
#include "qt_desktop.h"
#include "qt_common.h"
#include "qt_tools.h"
 #include "spdlog/spdlog.h"
 #include "spdlog/sinks/rotating_file_sink.h"
#include <iostream>

void initSpdlog() {
    try {
        // Create a file rotating logger with 5mb size max and 3 rotated files
        // auto max_size = 1048576 * 10;
        // auto max_files = 3;
        // auto logger = spdlog::rotating_logger_mt("spdlog", "logs/WeTools.txt", max_size, max_files);

        auto logger = spdlog::rotating_logger_mt("WeTools", "logs/WeTools.log", 1024 * 1024 * 10, 3);
        logger->set_level(spdlog::level::debug);
        logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e %t %l] %v");
        logger->flush_on(spdlog::level::debug);
        spdlog::set_default_logger(logger);
    } catch (const spdlog::spdlog_ex &ex) {
        std::cerr << ex.what() << '\n';
    }
}

#undef main
int main(int argc, char *argv[]) {
    initSpdlog();
    QApplication app(argc, argv);
    Qt_Tools::getInstance()->loadResource(RESOURCE_RSS_PATH);
    Qt_Tools::getInstance()->loadPlatGrayStyle();
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
