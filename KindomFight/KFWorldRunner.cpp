#include "KFWorldRunner.h"
#include "KFDate.h"
#include "KingdomFightWindow.h"
#include "DataBase/KFDataBase.h"
#include "Building/City.h"

KFWorldRunner::KFWorldRunner(KFDataBase *database, KingdomFightWindow *mainWindow,
                             QObject *parent) : QObject(parent),
    m_dbConn(database),
    m_mainWindow(mainWindow),
    m_kfDate(new KFDate(this))
{
    m_kfDate->setDate(400, 3, 5);
    connect(m_kfDate, SIGNAL(dateSig_newDay(QDate)), SLOT(on_newDay(QDate)));
    connect(m_kfDate, SIGNAL(dateSig_firstDayOfTen(QDate)), SLOT(on_firstDayOfTen(QDate)));

    initCityList();
}

KFWorldRunner::~KFWorldRunner()
{
    while (!m_cityList.isEmpty()) {
        City *city = m_cityList.last();
        delete city;
        m_cityList.removeLast();
    }
}

void KFWorldRunner::startRunner()
{
    m_kfDate->start();
}

void KFWorldRunner::on_newDay(QDate date)
{
    QString strText = tr("A new day : ") + date.toString();
    m_mainWindow->showTextMessage(strText);
}

void KFWorldRunner::on_firstDayOfTen(QDate date)
{
    QString strText = tr("First day of ten : ") + date.toString() + tr("assign task");
    m_mainWindow->showTextMessage(strText);
}

void KFWorldRunner::on_firstDayOfMonth(QDate date)
{
    Q_UNUSED(date);
}

void KFWorldRunner::initCityList()
{
    m_dbConn->getAllCitys(m_cityList);
}
