#ifndef CNEWSITEMDELEGATE_H
#define CNEWSITEMDELEGATE_H

#include <QStyledItemDelegate>

class CWebSiteItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CWebSiteItemDelegate(QObject *parent = 0);

    // painting
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;

signals:

public slots:

};

#endif // CNEWSITEMDELEGATE_H
