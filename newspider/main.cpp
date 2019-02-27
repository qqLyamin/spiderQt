#include "widget.h"
#include "mypause.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translation;
    translation.load(QLocale::system(), "spider", "_");
    a.installTranslator(&translation);

    Widget w;
    //pause::setpause(3);
    w.show();
    //pause::setpause(3);
    //w.setWindowState(Qt::WindowMaximized);
    return a.exec();
}
