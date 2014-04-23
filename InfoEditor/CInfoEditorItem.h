#ifndef CINFOEDITORITEM_H
#define CINFOEDITORITEM_H

#include <QGraphicsObject>
#include "SEditorItemInfo.h"
#include "IELine.h"

class CInfoEditorItem : public QGraphicsObject
{
public:
    CInfoEditorItem(QGraphicsItem *parent = 0);

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    //
    QString getItemContentText();
    QString getItemTitle();
    void setItemContextText(const QString& strText);
    void setItemTitle(const QString& strTitle);

    //
    bool isPointInBorder(const QPointF& point);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public:
    SEditorItemInfo m_info;
    QSize m_boudSize;
    QPointF m_mousePoint;
    bool m_mousePressed;
    bool m_itemSelected;
};

#endif // CINFOEDITORITEM_H
