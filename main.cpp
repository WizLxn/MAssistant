#include "MA_TrayIcon.h"
#include "MA_MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QObject::tr("MAssistant"));
    a.setQuitOnLastWindowClosed(false);

    MA_MainWindow w;
    MA_TrayIcon m(w);
    m.show();

    return a.exec();
}
