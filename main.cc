#include "xewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XeWidget w;
    w.show();
    return a.exec();
}
