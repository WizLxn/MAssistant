#include "CInfoEditorItem.h"
#include <QFont>
#include <QFontMetrics>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>

CInfoEditorItem::CInfoEditorItem(QGraphicsItem* parent) : QGraphicsObject(parent),
    m_mousePressed(false)
{
}

QRectF CInfoEditorItem::boundingRect() const
{
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
    if (m_itemSelected)
    {
        pen.setWidth(2);
        pen.setColor(Qt::blue);
        painter->setPen(pen);
    }
    painter->drawRect(rcBound);

    pen.setWidth(m_info.nFontSize);
    pen.setColor(m_info.clFontColor);
    painter->setPen(pen);
    rcBound.adjust(m_info.nTextMargin, m_info.nTextMargin, -m_info.nTextMargin, -m_info.nTextMargin);
    painter->drawText(rcBound, Qt::AlignCenter | Qt::TextWordWrap, m_info.strContext);
}

QString CInfoEditorItem::getItemContentText()
{
    return m_info.strContext;
}

QString CInfoEditorItem::getItemTitle()
{
    return m_info.strTitle;
}

void CInfoEditorItem::setItemContextText(const QString &strText)
{
    m_info.strContext = strText;
}

void CInfoEditorItem::setItemTitle(const QString &strTitle)
{
    m_info.strTitle = strTitle;
}

bool CInfoEditorItem::isPointInBorder(const QPointF &point)
{
    int nMargin = 3;
    QRectF innerRect = boundingRect();
    innerRect.adjust(nMargin, nMargin, -nMargin, -nMargin);
    QRectF outerRect = boundingRect();
    outerRect.adjust(-nMargin, -nMargin, nMargin, nMargin);

    return (!innerRect.contains(point)) && outerRect.contains(point);
}

void CInfoEditorItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_mousePoint = event->pos();
    m_mousePressed = true;
}

void CInfoEditorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    if (isPointInBorder(event->pos()))
//    {
//        this->setCursor(Qt::ArrowCursor);
//    }

//    if (m_mousePressed)
//    {
//        // mouse point in border
//        if ()
//        {
//        }
//        else
//        {
//            QPointF curMousePos = event->pos();
//            QPointF curItemPos = pos();
//            setPos(curItemPos.x() + curMousePos.x() - m_mousePoint.x(),
//                   curItemPos.y() + curMousePos.y() - m_mousePoint.y());
//        }
//    }
}

void CInfoEditorItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mousePressed = false;
    m_mousePoint = QPointF(0, 0);
}
