#include "KFDataBase.h"
#include "../Building/City.h"

KFDataBase::KFDataBase(QObject *parent) :
    QObject(parent)
{
}

bool KFDataBase::getAllCitys(QList<City *> &cityList)
{
    while (!cityList.isEmpty())
    {
        City *city = cityList.first();
        delete city;
        cityList.removeFirst();
    }

    for (int i = 0; i < 5; i++)
    {
        City *city = new City("City : " + QString::number(i));
        city->setName("City : " + QString::number(i));
        city->setPopulation(1000 + i*100);
        cityList.append(city);
    }
    return true;
}
