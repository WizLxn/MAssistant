#ifndef KFDATE_H
#define KFDATE_H

#include <QDate>

#include <QObject>
#include <QDate>
#include <QTimer>

class KFDate:public QObject
{
    Q_OBJECT
public:
    explicit KFDate(QObject *parent = 0);
    ~KFDate();
    void setDate(int y, int m, int d);
    void start();
    inline bool isLastDayOfMon();
    inline bool isFirstOfTen();
    QString toString()const;
    QDate getQDate()const;
public slots:
    void aNewDay();
signals:
    void dateSig_newDay(QDate date);
    void dateSig_firstDayOfTen(QDate date);
    void dateSig_LastDayOfMon(QDate date);
private:
    QDate m_date;
    QTimer *m_timer;
};

#endif // KFDATE_H
