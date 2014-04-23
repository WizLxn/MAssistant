#ifndef MAMISC_H
#define MAMISC_H

#include <QColor>

class MAMisc
{
public:
    MAMisc();
};

int QColorToInt(const QColor &color);
QColor IntToQColor(const int &intColor);

#endif // MAMISC_H
