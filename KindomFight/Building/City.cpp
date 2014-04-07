#include "City.h"

City::City(const QString &strHashID)
{
    m_data.strHashID = strHashID;
}

QString City::getName() const
{
    return m_data.strCityName;
}

void City::setName(const QString &name)
{
    m_data.strCityName = name;
}

QString City::getHashID() const
{
    return m_data.strHashID;
}

int City::getPopulation() const
{
    return m_data.population;
}

void City::setPopulation(int population)
{
    m_data.population = population;
}
