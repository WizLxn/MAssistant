#ifndef MAWINDOWSTYLE_H
#define MAWINDOWSTYLE_H

#include <QProxyStyle>

class CWindowStyle : public QProxyStyle
{
public:
    CWindowStyle();

    void drawControl(ControlElement element, const QStyleOption * option,
                     QPainter * painter, const QWidget * widget = 0) const;
};

#endif // MAWINDOWSTYLE_H
