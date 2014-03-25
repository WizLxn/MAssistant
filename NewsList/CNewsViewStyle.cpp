#include "CNewsViewStyle.h"
#include <QStyleOption>
#include <QPainter>

CNewsViewStyle::CNewsViewStyle(QStyle *style) : QProxyStyle(style)
{
}

void CNewsViewStyle::drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    switch (element)
    {
    case CE_ItemViewItem:
    {
        const QStyleOptionViewItemV4 *vopt = qstyleoption_cast<const QStyleOptionViewItemV4 *>(option);

        if (!vopt->index.parent().isValid())
        {
            // draw root item
            painter->save();
//            QRect rcd(vopt->rect);
//            rcd.setWidth(painter->window().width());
//            painter->setBrush(QBrush(Qt::gray));
//            painter->setPen(Qt::NoPen);
//            painter->drawRect(rcd);
            painter->setBrush(Qt::NoBrush);
            painter->setPen(QPen(Qt::white));
            QString strText = vopt->index.data().toString();
            painter->drawText(vopt->rect, Qt::AlignCenter, strText);
            painter->restore();
        }
        else
        {
            //draw normal Item
            painter->save();
            if (vopt->state & QStyle::State_Selected)
            {
                painter->setBrush(QBrush(Qt::gray));
                painter->setPen(Qt::NoPen);
                painter->drawRect(vopt->rect);
                QFont font("arial");
                font.setBold(true);
                painter->setFont(font);
                painter->setPen(QPen(Qt::white));
                QString strText = vopt->index.data().toString();
                painter->drawText(vopt->rect, Qt::AlignVCenter | Qt::AlignLeft, strText);
            }
            else
            {
                painter->setBrush(Qt::NoBrush);
                QFont font("arial");
                font.setBold(true);
                painter->setFont(font);
                painter->setPen(QPen(Qt::black));
                QString strText = vopt->index.data().toString();
                painter->drawText(vopt->rect, Qt::AlignVCenter | Qt::AlignLeft, strText);
            }
            painter->restore();
        }
    }
        break;

    default:
        break;
    }
}

void CNewsViewStyle::drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    switch (pe)
    {
    case PE_PanelItemViewRow:
    {
        const QStyleOptionViewItemV4 *vopt = qstyleoption_cast<const QStyleOptionViewItemV4 *>(opt);
        QRect rc(vopt->rect);
        rc.setWidth(p->window().width());
        QRect rcd(rc);

        QColor bgColor;
        if (vopt->state & QStyle::State_Selected) {
            bgColor = QColor(Qt::gray);
        } else {
            bgColor = QColor(Qt::white);
        }

        p->save();
        if (vopt->state & QStyle::State_Selected) {
            p->fillRect(rcd, bgColor);
            rcd.setWidth(5); // FIXME
            p->fillRect(rcd, QColor("#0073c5"));
        } else {
            p->fillRect(rcd, bgColor);
        }
        p->restore();


        return;
    }
        break;
    default:
        break;
    }

}
