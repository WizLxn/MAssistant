#ifndef CITY_H
#define CITY_H

#include <QString>
#include "Building.h"

struct CityData{
    QString strCityName;
    QString strHashID;
    int population;
    int money;
    int army;
    int commer;
    int agricul;
};

class City : public Building
{
public:
    City(const QString& strHashID);

    //data set and get
    QString getName() const;
    void setName(const QString& name);
    QString getHashID() const;
    int getPopulation() const;
    void setPopulation(int population);

private:
    CityData m_data;
};

#endif // CITY_H
