#include "maTrayIcon.h"
#include <QApplication>
#include <QIcon>
#include <QDebug>
#include <QDir>
#include "maMainWindow.h"

CTrayIcon::CTrayIcon(CMainWindow& window, QObject *parent) :
    QSystemTrayIcon(parent),m_mainWindow(window)
{
    setIcon(QIcon(":/dragon.png"));
    createContextMenu();
    setToolTip("MyTrayIcon");
    qDebug()<<QDir::currentPath();
    connect(this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), SLOT(on_tryaIcon_clicked(QSystemTrayIcon::ActivationReason)));
}

CTrayIcon::~CTrayIcon()
{
}

void CTrayIcon::showMainWindow()
{
    m_mainWindow.show();
    showMessage(tr("hahaya"), tr("托盘测试"), QSystemTrayIcon::Information, 5000);
}

void CTrayIcon::on_tryaIcon_clicked(QSystemTrayIcon::ActivationReason reasion)
{
    switch (reasion) {
    case QSystemTrayIcon::Trigger:

        break;
    case QSystemTrayIcon::DoubleClick:
        m_mainWindow.show();
        break;
    default:
        break;
    }
}

void CTrayIcon::on_message_remind(QString msg)
{
    showMessage(tr("Info"), msg, QSystemTrayIcon::Information, 5000);
}

void CTrayIcon::createContextMenu()
{
    QAction* action = m_menu.addAction(tr("Quit"));
    action->setIcon(QIcon(":/exit.png"));
    connect(action, SIGNAL(triggered()), qApp, SLOT(quit()));

    action = m_menu.addAction(tr("MainWindow"));
    connect(action, SIGNAL(triggered()), this, SLOT(showMainWindow()));

    setContextMenu(&m_menu);
}
