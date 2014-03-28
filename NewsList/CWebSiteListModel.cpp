#include "CWebSiteListModel.h"

CWebSiteListModel::CWebSiteListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void CWebSiteListModel::addWebSite(const SWebSite &site)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_sites << site;
    endInsertRows();
}

int CWebSiteListModel::rowCount(const QModelIndex &/*parent*/) const
{
    return m_sites.count();
}

QVariant CWebSiteListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > m_sites.count())
        return QVariant();

    const SWebSite &site = m_sites[index.row()];
    if (role == WebUseableRole)
        return site.enable;
    else if (role == WebSiteRole)
        return site.strUrl;
    return QVariant();
}
