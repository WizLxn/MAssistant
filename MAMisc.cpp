#include "MAMisc.h"

MAMisc::MAMisc()
{
}


int QColorToInt(const QColor &color)
{
    return (int)(((unsigned int)color.blue()<< 16) | (unsigned short)(((unsigned short)color.green()<< 8) | color.red()));
}


QColor IntToQColor(const int &intColor)
{
    int red = intColor & 255;
    int green = intColor >> 8 & 255;
    int blue = intColor >> 16 & 255;
    return QColor(red, green, blue);
}
