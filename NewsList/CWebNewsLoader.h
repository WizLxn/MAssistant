#ifndef CWEBNEWSLOADER_H
#define CWEBNEWSLOADER_H

#include <QObject>
#include <QStringList>

class QWebView;
class CWebNewsLoader : public QObject
{
    Q_OBJECT
public:
    explicit CWebNewsLoader(QObject *parent = 0);

    void loadWebPageNewsList(const QString& webSite);
    void loadRssNewsList(const QString& webSite);

public slots:
    void on_webPageLoadFinished(bool res);

signals:
    void newsListLoadFinished(QString webSite, QStringList newsList);

private:
    QWebView* m_webView;
};

#endif // CWEBNEWSLOADER_H
