#ifndef CNEWSITEMDELEGATE_H
#define CNEWSITEMDELEGATE_H

#include <QStyledItemDelegate>

class CWebSiteItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CWebSiteItemDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const;

    bool editorEvent(QEvent * event, QAbstractItemModel * model, const QStyleOptionViewItem & option,
                     const QModelIndex & index);

signals:

public slots:
    void on_checkBox_Toggle(bool b);

};

#endif // CNEWSITEMDELEGATE_H
