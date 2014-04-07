#ifndef KFDATABASE_H
#define KFDATABASE_H

#include <QObject>
#include <QList>

class City;
class KFDataBase : public QObject
{
    Q_OBJECT
public:
    explicit KFDataBase(QObject *parent = 0);

    //
    bool getAllCitys(QList<City*>& cityList);
signals:

public slots:

};

#endif // KFDATABASE_H
