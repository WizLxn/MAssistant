#ifndef CWEBSITELISTMODEL_H
#define CWEBSITELISTMODEL_H

#include <QStandardItemModel>

struct SWebSite
{
    bool enable;
    QString strUrl;
};

enum webRole{
    WebUseableRole = Qt::UserRole+1,
    WebSiteRole
};

class CWebSiteListModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit CWebSiteListModel(QObject *parent = 0);

    void addWebSite(const SWebSite &site);

    bool getWebSite(SWebSite& site, int row) const;

    //QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

private:


};

#endif // CWEBSITELISTMODEL_H
