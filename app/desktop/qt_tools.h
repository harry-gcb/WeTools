#ifndef QT_TOOLS_H_
#define QT_TOOLS_H_

#include "QtGui/QPixmap"
#include "QtWidgets/QPushButton"
#include "singleton.h"

class Qt_Tools: public Singleton<Qt_Tools> {
    friend class Singleton<Qt_Tools>;
public:
    void loadResource(const QString &resource);
    void loadPlatGrayStyle();
    void loadBlackSoftStyle();
    void loadLightBlueStyle();
    QPixmap scaledPixmap(const QPixmap &src, int width, int height);
    void setButtonPixmap(QPushButton *button, const QString &imgName);
private:
    void loadStyleSheet(const QString &style);
    // static QPixmap radiusPixmap(const QPixmap &src, int radius);
};

#endif

