#include "DataIP.h"
#include <QApplication>
#include <QTranslator>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.addLibraryPath("plugins");

    QTranslator *translator = new QTranslator(&a);
    if(translator->load(":/qt_zh_CN.qm"))
    {
        a.installTranslator(translator);
    }

    QFile file("./DataIP.qss");
    file.open(QIODevice::ReadOnly);
    a.setStyleSheet(file.readAll());

    Widget w;
    w.showFullScreen();
    w.show();

    return a.exec();
}
