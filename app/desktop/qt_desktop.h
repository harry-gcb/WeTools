#ifndef QT_DESKTOP_H_
#define QT_DESKTOP_H_

#include "QtWidgets/QMainWindow"
#include "ui_desktop.h"

class Qt_Desktop : public QWidget {
    Q_OBJECT
public:
    explicit Qt_Desktop(QWidget *parent = Q_NULLPTR);

private:
    Ui::Desktop ui_;
};

#endif