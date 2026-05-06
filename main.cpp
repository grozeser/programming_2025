#include <QApplication>
#include "program2window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Program2Window w;
    w.show();
    return a.exec();
}
