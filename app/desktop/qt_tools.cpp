
#include "QtWidgets/QApplication"
#include "QtGui/QPalette"
#include "QtCore/QResource"
#include "QtCore/QFile"
#include "QtGui/QBitmap"
#include "qt_tools.h"
#include "qt_common.h"
#include "spdlog/spdlog.h"

// /* 圆角图片
//  * src 原图片
//  * radius 图片半径 */
// QPixmap Qt_Tools::radiusPixmap(const QPixmap &src, int radius) {
//     // 无效图片不处理
//     if (src.isNull()) {
//         return src;
//     }
//     // 压缩图片
//     QPixmap pixmap = scaledPixmap(src, radius * 2);

//     QPixmap dest(2*radius, 2*radius);
//     dest.fill(Qt::transparent);
//     QPainter painter(&dest);
//     // 抗锯齿 + 平滑边缘处理
//     painter.setRenderHints(QPainter::Antialiasing, true);
//     painter.setRenderHints(QPainter::SmoothPixmapTransform, true);
//     // 裁剪为圆角
//     QPainterPath path;
//     path.addEllipse(0, 0, 2*radius, 2*radius);
//     painter.setClipPath(path);
//     painter.drawPixmap(0, 0, 2*radius, 2*radius, pixmap);

//     return dest;    
// }



void Qt_Tools::loadStyleSheet(const QString &style) {
    //加载样式表
    QFile qss(style);
    if(qss.open(QFile::ReadOnly))
    {
        QString stylesheet = QLatin1String(qss.readAll());
        QString paletteColor = stylesheet.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(stylesheet);
    }
}

void Qt_Tools::loadResource(const QString &resource) {
    bool ret = QResource::registerResource(qApp->applicationDirPath() + resource);
    if (!ret) {
        QString str = qApp->applicationDirPath() + resource;
        spdlog::error("loadResource error: {}", str.toStdString());
    }
}

void Qt_Tools::loadPlatGrayStyle() {
    loadStyleSheet(THEME_CSS_FLATGRAY);
}
void Qt_Tools::loadBlackSoftStyle() {

}
void Qt_Tools::loadLightBlueStyle() {

}

// /* 压缩图片为指定宽高 */
QPixmap Qt_Tools::scaledPixmap(const QPixmap &src, int width, int height) {
    return src.scaled(width, (height == 0 ? width : height),
                Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void Qt_Tools::setButtonPixmap(QPushButton *button, const QString &imgName) {
    if (!button) {
        return;
    }
    QPixmap srcPixmap(imgName);
    if (srcPixmap.isNull()) {
        spdlog::error("srcPixmap is NULL, {}", imgName.toStdString());
        return;
    }
    QPixmap dstPixmap(scaledPixmap(srcPixmap, button->width(), button->height()));
    if (dstPixmap.isNull()) {
        spdlog::error("dstPixmap is NULL, {}", imgName.toStdString());
        return;
    }

    button->setIconSize(dstPixmap.size());
    button->setIcon(QIcon(dstPixmap));
    button->setMask(dstPixmap.mask());

    //button->setFlat(true);
    //button->setAutoFillBackground(true);


    // button
}

