#include <QtWidgets/QApplication>
#include "qt_desktop.h"

#undef main
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Qt_Desktop desktop;
    desktop.show();
    return app.exec();
}
