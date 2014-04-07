#include "KFDate.h"

KFDate::KFDate(QObject *parent) : QObject(parent),
    m_timer(new QTimer(this))
{
    connect(this->m_timer,SIGNAL(timeout()),this,SLOT(aNewDay()));
}

KFDate::~KFDate()
{
}

void KFDate::setDate(int y, int m, int d)
{
    m_date.setDate(y, m, d);
}

void KFDate::start()
{
    m_timer->start(3000);
}

void KFDate::aNewDay()
{
    m_date=m_date.addDays(1);
    emit dateSig_newDay(m_date);

    if(isFirstOfTen())
        emit dateSig_firstDayOfTen(m_date);

    if(isLastDayOfMon())
        emit dateSig_LastDayOfMon(m_date);
}

bool KFDate::isLastDayOfMon()
{
    if(m_date.day()==m_date.daysInMonth())
        return true;
    return false;
}

bool KFDate::isFirstOfTen()
{
    if(m_date.day()%10==1)
        return true;
    return false;
}

QString KFDate::toString() const
{
    return m_date.toString("yyyy-MM-dd");
}

QDate KFDate::getQDate() const
{
    return m_date;
}
