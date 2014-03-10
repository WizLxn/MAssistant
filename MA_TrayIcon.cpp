#include "MA_TrayIcon.h"
#include <QApplication>
#include <QIcon>
#include <QDebug>

MA_TrayIcon::MA_TrayIcon(MA_MainWindow& window, QObject *parent) :
    QSystemTrayIcon(parent),m_mainWindow(window)
{
    setIcon(QIcon(":\rss.png"));
    createContextMenu();
    qDebug()<<QSystemTrayIcon::isSystemTrayAvailable();
}

void MA_TrayIcon::showMainWindow()
{
    m_mainWindow.show();
}

void MA_TrayIcon::createContextMenu()
{
    QAction* action = m_menu.addAction(tr("Quit"));
    action->setIcon(QIcon(":\exit.png"));
    connect(action, SIGNAL(triggered()), qApp, SLOT(quit()));

    action = m_menu.addAction(tr("MainWindow"));
    connect(action, SIGNAL(triggered()), this, SLOT(showMainWindow()));

    setContextMenu(&m_menu);
}
