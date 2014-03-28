#ifndef MATIMEDREMINDER_H
#define MATIMEDREMINDER_H

#include <QTimer>

class CTimedReminder : public QTimer
{
    Q_OBJECT
public:
    explicit CTimedReminder(QObject *parent = 0);

    int nInterval() const;
    void setInterval(int nInterval);

    int nCyclesNum() const;
    void setNCyclesNum(int nCyclesNum);

    QString strReminder() const;
    void setStrReminder(const QString &strReminder);

    void startReminder(int nInterval = 1000, int nCycle = 1, const QString& strRminder = "-Nothing-");
signals:
    void timeToRemid(QString strRemind);

private slots:
    void on_timeOut();

protected:
    int m_nCyclesNum;
    int m_nSecondInterval;
    QString m_strReminder;
};

#endif // MATIMEDREMINDER_H
