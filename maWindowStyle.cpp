#include "maWindowStyle.h"
#include <QStyleOption>
#include <QPainter>

CWindowStyle::CWindowStyle()
{
}

void CWindowStyle::drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    switch (element) {
    case QStyle::CE_PushButton:
        if (const QStyleOptionButton *button
                = qstyleoption_cast<const QStyleOptionButton *>(option)) {

            painter->save();
            painter->setPen(Qt::red);
            painter->setBrush(Qt::yellow);
            painter->drawRect(button->rect);
            painter->drawText(button->rect, Qt::AlignVCenter, button->text);
            painter->restore();

        }

        break;
    default:
        break;
    }
}
