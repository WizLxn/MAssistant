#include "CInfoEditorItem.h"
#include <QFont>
#include <QFontMetrics>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

CInfoEditorItem::CInfoEditorItem(QGraphicsItem* parent) : QGraphicsObject(parent),
    m_mousePressed(false)
{
}

QRectF CInfoEditorItem::boundingRect() const
{
//    QPainter painter;
//    QFont font(m_info.strFontName);
//    QPen pen;
//    pen.setWidth(m_info.nFontSize);
//    painter.setFont(font);
//    painter.setPen(pen);
//    QRect rcBound(0, 0, 0, 0);
//    painter.drawText(0, 0, 0, 0, Qt::AlignCenter, m_info.strContext, &rcBound);
//    rcBound.adjust(-m_info.nTextMargin, -m_info.nTextMargin, m_info.nTextMargin, m_info.nTextMargin);

    return QRect(-m_boudSize.width()/2, -m_boudSize.height()/2, m_boudSize.width(), m_boudSize.height());
}

void CInfoEditorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QFont font(m_info.strFontName);
    QPen pen;
    painter->setFont(font);

    pen.setWidth(0);
    painter->setPen(pen);
    QRectF rcBound = boundingRect();
    painter->drawRect(rcBound);

    pen.setWidth(m_info.nFontSize);
    painter->setPen(pen);
    rcBound.adjust(m_info.nTextMargin, m_info.nTextMargin, -m_info.nTextMargin, -m_info.nTextMargin);
    painter->drawText(rcBound, Qt::AlignCenter | Qt::TextWordWrap, m_info.strContext);
}

void CInfoEditorItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_mousePoint = event->pos();
    m_mousePressed = true;
}

void CInfoEditorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_mousePressed)
    {
        QPointF curMousePos = event->pos();
        QPointF curItemPos = pos();
        setPos(curItemPos.x() + curMousePos.x() - m_mousePoint.x(),
               curItemPos.y() + curMousePos.y() - m_mousePoint.y());
        //m_mousePoint = curMousePos;
    }
}

void CInfoEditorItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mousePressed = false;
    m_mousePoint = QPointF(0, 0);
}
