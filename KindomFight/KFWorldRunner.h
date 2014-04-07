#ifndef KFWORLDRUNNER_H
#define KFWORLDRUNNER_H

#include <QObject>
#include <QList>
#include <QDate>

class City;
class KFDate;
class KFDataBase;
class KingdomFightWindow;
class KFWorldRunner : public QObject
{
    Q_OBJECT
public:
    explicit KFWorldRunner(KFDataBase *database, KingdomFightWindow *mainWindow,
                           QObject *parent = 0);
    ~KFWorldRunner();
    void startRunner();
signals:

private slots:
    void on_newDay(QDate date);
    void on_firstDayOfTen(QDate date);
    void on_firstDayOfMonth(QDate date);

private:
    void initCityList();

private:
    KFDataBase *m_dbConn;
    KingdomFightWindow *m_mainWindow;
    KFDate *m_kfDate;
    QList<City*> m_cityList;
};

#endif // KFWORLDRUNNER_H
