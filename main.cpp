#include "maTrayIcon.h"
#include "maMainWindow.h"
#include "maMAssistant.h"
#include "InfoEditor/CInfoEditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QObject::tr("MAssistant"));
    a.setQuitOnLastWindowClosed(false);
    a.setWindowIcon(QIcon(":/dragon.png"));

    CMainWindow w;
    CTrayIcon m(w);
    CMAssistant assist(m, w);

    assist.showTrayIcon();
//    m.show();

//    CInfoEditor editor;
//    editor.show();

    return a.exec();
}
