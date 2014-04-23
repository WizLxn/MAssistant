#include "maTrayIcon.h"
#include <QApplication>
#include <QIcon>
#include <QDebug>
#include <QDir>
#include "maMainWindow.h"
#include "NewsList/CNewsListWidget.h"
#include "InfoEditor/CInfoEditor.h"
#include "KindomFight/KFMain.h"

CTrayIcon::CTrayIcon(CMainWindow& window, QObject *parent) :
    QSystemTrayIcon(parent),
    m_mainWindow(window),
    m_newsListWidget(0),
    m_infoEditor(0),
    m_kfMain(0)
{
    setIcon(QIcon(":/dragon.png"));
    createContextMenu();
    setToolTip("MyTrayIcon");
    qDebug()<<QDir::currentPath();
    connect(this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), SLOT(on_tryaIcon_clicked(QSystemTrayIcon::ActivationReason)));
}

CTrayIcon::~CTrayIcon()
{
    if (m_newsListWidget)
    {
        m_newsListWidget->deleteLater();
        m_newsListWidget = 0;
    }
    if (m_infoEditor)
    {
        m_infoEditor->deleteLater();
        m_infoEditor = 0;
    }
    if (m_kfMain)
    {
        m_kfMain->closeMainWindow();
        m_kfMain->deleteLater();
        m_kfMain = 0;
    }
}

void CTrayIcon::showMainWindow()
{
    m_mainWindow.show();
}

void CTrayIcon::showNewsListWidget()
{
    if (!m_newsListWidget)
    {
        m_newsListWidget = new CNewsListWidget;
    }
    m_newsListWidget->show();
}

void CTrayIcon::showInfoEditor()
{
    if (!m_infoEditor)
    {
        m_infoEditor = new CInfoEditor;
    }
    m_infoEditor->show();
}

void CTrayIcon::showKFMainWindow()
{
    if (!m_kfMain)
    {
        m_kfMain = new KFMain;
        connect(m_kfMain, SIGNAL(mainWindowClosed()), SLOT(on_KFMainWindowClosed()));
    }
    m_kfMain->showKFMainWindow();
}

void CTrayIcon::on_KFMainWindowClosed()
{
    m_kfMain->deleteLater();
    m_kfMain = 0;
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

    action = m_menu.addAction(tr("NewList"));
    connect(action, SIGNAL(triggered()), this, SLOT(showNewsListWidget()));

    action = m_menu.addAction(tr("InfoEditor"));
    connect(action, SIGNAL(triggered()), this, SLOT(showInfoEditor()));

    action = m_menu.addAction(tr("KingdomFight"));
    connect(action, SIGNAL(triggered()), this, SLOT(showKFMainWindow()));

    setContextMenu(&m_menu);
}
