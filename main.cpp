#include "maTrayIcon.h"
#include "maMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QObject::tr("MAssistant"));
    a.setQuitOnLastWindowClosed(false);
    a.setWindowIcon(QIcon(":/rss.png"));

    CMainWindow w;
    CTrayIcon m(w);
    m.show();

    return a.exec();
}
