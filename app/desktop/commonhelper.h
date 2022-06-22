#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QString>
#include <QFile>
#include <QApplication>
#include <QDebug>
#include <QColor>
#include <QPalette>

/**
 * @brief 通用功能辅助类
 */
class CommonHelper
{
public:
    /**
     * @brief 为应用程序设置QSS样式表
     * @param filepath，输入参数，QSS文件路径
     */
    static void setStyleSheet(const QString& filepath)
    {
        //加载样式文件
        QFile qss(filepath);
        if(qss.open(QFile::ReadOnly))
        {
            QString stylesheet = QLatin1String(qss.readAll());
            QString paletteColor = stylesheet.mid(20, 7);
            qApp->setPalette(QPalette(QColor(paletteColor)));
            qApp->setStyleSheet(stylesheet);
        }
    }
};

#endif // COMMONHELPER_H