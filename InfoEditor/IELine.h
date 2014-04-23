#ifndef IELINE_H
#define IELINE_H

#include <QList>
#include <QPoint>

class IELine
{
public:
    IELine();
    IELine(int width, int color, bool close);

protected:
    int m_width;
    int m_color;
    bool m_close;
    QList<QPoint> m_points;
};

#endif // IELINE_H
