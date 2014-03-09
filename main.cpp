#include "MA_MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MA_MainWindow w;
    w.show();

    return a.exec();
}
