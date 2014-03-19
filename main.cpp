#include "maTrayIcon.h"
#include "maMainWindow.h"
#include <QApplication>
#include "InfoEditor/CInfoEditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QObject::tr("MAssistant"));
    a.setQuitOnLastWindowClosed(false);
    a.setWindowIcon(QIcon(":/dragon.png"));

//    CMainWindow w;
//    CTrayIcon m(w);
//    m.show();

    CInfoEditor editor;
    editor.show();

    return a.exec();
}
