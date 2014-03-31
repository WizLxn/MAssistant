#include "CWebSiteListModel.h"
#include <QStandardItem>

CWebSiteListModel::CWebSiteListModel(QObject *parent) :
    QStandardItemModel(parent)
{
}

void CWebSiteListModel::addWebSite(const SWebSite &site)
{
    QStandardItem* item = new QStandardItem(site.strUrl);
    item->setCheckable(true);
    Qt::CheckState checkState = site.enable ? Qt::Checked : Qt::Unchecked;
    item->setCheckState(checkState);
    appendRow(item);
}

bool CWebSiteListModel::getWebSite(SWebSite &site, int row) const
{
    if (row< 0 || row > rowCount())
        return false;

    QString strUrl = item(row)->text();
    bool checkState = (item(row)->checkState() == Qt::Checked);
    site.enable = checkState;
    site.strUrl = strUrl;

    return true;
}

//QVariant CWebSiteListModel::data(const QModelIndex &index, int role) const
//{
//    if (index.row() < 0 || index.row() > m_sites.count())
//        return QVariant();

//    const SWebSite &site = m_sites[index.row()];
//    if (role == WebUseableRole)
//        return site.enable;
//    else if (role == WebSiteRole)
//        return site.strUrl;

//    return QStandardItemModel::data(index, role);
//}
