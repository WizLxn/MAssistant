#ifndef CWEBSITELISTMODEL_H
#define CWEBSITELISTMODEL_H

#include <QAbstractListModel>

struct SWebSite
{
    bool enable;
    QString strUrl;
};

enum webRole{
    WebUseableRole = Qt::UserRole+1,
    WebSiteRole
};

class CWebSiteListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CWebSiteListModel(QObject *parent = 0);

    void addWebSite(const SWebSite &site);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

private:
    QList<SWebSite> m_sites;


};

#endif // CWEBSITELISTMODEL_H
