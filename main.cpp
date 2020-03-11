#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget *desktop = qApp->desktop();
    Widget w;
    w.move(desktop->width() / 2 - w.width() / 2, desktop->height() / 2 - w.height() / 2);
    w.resize(900, 600);



    w.show();

    return a.exec();
}
