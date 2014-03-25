#include "CWebSiteItemDelegate.h"
#include <QStyleOptionViewItem>
#include <QPainter>

CWebSiteItemDelegate::CWebSiteItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void CWebSiteItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.parent().isValid())
    {
        // draw root item
        painter->save();
        painter->setBrush(QBrush(Qt::gray));
        painter->setPen(Qt::NoPen);
        painter->drawRect(option.rect);
        painter->setPen(QPen(Qt::white));
        QString strText = index.data().toString();
        painter->drawText(option.rect, Qt::AlignCenter, strText);
        painter->restore();
    }
    else
    {
        //draw normal Item
        painter->save();
        painter->setBrush(Qt::NoBrush);
        QFont font("arial");
        font.setBold(true);
        painter->setFont(font);
        painter->setPen(QPen(Qt::black));
        QString strText = index.data().toString();
        painter->drawText(option.rect, Qt::AlignCenter, strText);
        painter->restore();
    }
}

QSize CWebSiteItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);

    return option.rect.size();
}
