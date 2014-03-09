#include "MA_MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QObject::tr("MAssistant"));

    MA_MainWindow w;
    w.show();

    return a.exec();
}
