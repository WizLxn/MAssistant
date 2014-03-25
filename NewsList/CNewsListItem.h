#ifndef CNEWSLISTITEM_H
#define CNEWSLISTITEM_H

#include <QTreeWidgetItem>

class CNewsListRootItem : public QTreeWidgetItem
{
public:
    explicit CNewsListRootItem(QTreeWidgetItem *parent = 0);


};


class CNewsListContentItem : public QTreeWidgetItem
{
public:
    explicit CNewsListContentItem(QTreeWidgetItem *parent = 0);


};

#endif // CNEWSLISTITEM_H
