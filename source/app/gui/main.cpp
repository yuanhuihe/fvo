#include "fvoapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fvoApp w;
    w.show();
    return a.exec();
}
