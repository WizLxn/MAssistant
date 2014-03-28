#include "maTimedReminder.h"

CTimedReminder::CTimedReminder(QObject *parent) :
    QTimer(parent),
    m_nCyclesNum(0),
    m_nSecondInterval(0),
    m_strReminder(tr("-Nothing-"))
{
    connect(this, SIGNAL(timeout()), SLOT(on_timeOut()));
}
int CTimedReminder::nInterval() const
{
    return m_nSecondInterval;
}

void CTimedReminder::setInterval(int nInterval)
{
    m_nSecondInterval = nInterval;
}
int CTimedReminder::nCyclesNum() const
{
    return m_nCyclesNum;
}

void CTimedReminder::setNCyclesNum(int nCyclesNum)
{
    m_nCyclesNum = nCyclesNum;
}
QString CTimedReminder::strReminder() const
{
    return m_strReminder;
}

void CTimedReminder::setStrReminder(const QString &strReminder)
{
    m_strReminder = strReminder;
}

void CTimedReminder::startReminder(int nInterval, int nCycle, const QString &strRminder)
{
    m_nSecondInterval = nInterval;
    m_nCyclesNum = nCycle;
    m_strReminder = strRminder;
    start(m_nSecondInterval * 1000);
}

void CTimedReminder::on_timeOut()
{
    emit timeToRemid(m_strReminder);

    m_nCyclesNum--;
    if (m_nCyclesNum <= 0) {
        stop();
    }
}





