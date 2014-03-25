#ifndef CNEWSVIEWSTYLE_H
#define CNEWSVIEWSTYLE_H

#include <QProxyStyle>

class CNewsViewStyle : public QProxyStyle
{
public:
    CNewsViewStyle(QStyle *style = 0);

    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const;
    void drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w = 0) const;
};

#endif // CNEWSVIEWSTYLE_H
