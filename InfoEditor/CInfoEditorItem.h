#ifndef CINFOEDITORITEM_H
#define CINFOEDITORITEM_H

#include <QGraphicsItem>
#include "SEditorItemInfo.h"

class CInfoEditorItem : public QGraphicsItem
{
public:
    CInfoEditorItem();

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
public:
    SEditorItemInfo m_info;
    QSize m_boudSize;
};

#endif // CINFOEDITORITEM_H
