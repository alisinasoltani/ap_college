#include "cobitex.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cobitex w;
    w.show();
    return a.exec();
}
