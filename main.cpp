#include "engine.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Engine w;
    w.show();
    return a.exec();
}
