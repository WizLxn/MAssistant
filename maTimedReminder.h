#ifndef MATIMEDREMINDER_H
#define MATIMEDREMINDER_H

#include <QThread>

class CTimedReminder : public QThread
{
    Q_OBJECT
public:
    explicit CTimedReminder(QObject *parent = 0);

    int nInterval() const;
    void setNInterval(int nInterval);

    int nCyclesNum() const;
    void setNCyclesNum(int nCyclesNum);

    QString strReminder() const;
    void setStrReminder(const QString &strReminder);

signals:
    void timeToRemid(QString strRemind);

public slots:

protected:
    void run();

protected:
    int m_nCyclesNum;
    int m_nSecondInterval;
    QString m_strReminder;
};

#endif // MATIMEDREMINDER_H
