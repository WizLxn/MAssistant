#include "KFMain.h"
#include "DataBase/KFDataBase.h"
#include "KFWorldRunner.h"
#include "KingdomFightWindow.h"

KFMain::KFMain(QObject *parent) : QObject(parent),
    m_db(0),
    m_runner(0),
    m_mainWindow(0)
{

}

void KFMain::showKFMainWindow()
{
    m_db = new KFDataBase;
    m_mainWindow = new KingdomFightWindow(m_db);
    m_runner = new KFWorldRunner(m_db, m_mainWindow);
    connect(m_mainWindow, SIGNAL(destroyed()), SLOT(on_mainWindowClosed()));
    m_mainWindow->show();
    m_runner->startRunner();
}

void KFMain::closeMainWindow()
{
    m_mainWindow->close();
    m_mainWindow->deleteLater();
    delete m_runner;
    delete m_db;
}

void KFMain::on_mainWindowClosed()
{
    delete m_runner;
    delete m_db;
}
