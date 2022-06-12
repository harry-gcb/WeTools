#ifndef UI_DESKTOP_H_
#define UI_DESKTOP_H_

#include <QtWidgets/QApplication>

QT_BEGIN_NAMESPACE

class Ui_Desktop {
public:
    void setupUi(QWidget *win) {}
private:
    void retranslateUi(QMainWindow *win) {
        win->setWindowTitle(QCoreApplication::translate("frmMain", "MainWindow", nullptr));
    }
};

namespace Ui {
    class Desktop : public Ui_Desktop{};
};

QT_END_NAMESPACE

#endif