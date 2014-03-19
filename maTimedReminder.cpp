#include "maTimedReminder.h"

CTimedReminder::CTimedReminder(QObject *parent) :
    QThread(parent),
    m_nCyclesNum(0),
    m_nSecondInterval(0),
    m_strReminder(tr("-Nothing-"))
{
}
int CTimedReminder::nInterval() const
{
    return m_nSecondInterval;
}

void CTimedReminder::setNInterval(int nInterval)
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

void CTimedReminder::run()
{
    while (m_nCyclesNum > 0) {
        sleep(m_nSecondInterval);
        emit timeToRemid(m_strReminder);
        m_nCyclesNum--;
    }
}



