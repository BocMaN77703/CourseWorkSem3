#include "EditWindow.h"
#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow x;
    x.setWindowTitle("Pricelist of Computer Parts");
    x.show();
    return a.exec();
}