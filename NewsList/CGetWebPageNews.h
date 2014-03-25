#ifndef CGETWEBPAGENEWS_H
#define CGETWEBPAGENEWS_H

#include <QObject>

class QString;
class QStringList;
class QWebView;
class CGetWebPageNews : public QObject
{
    Q_OBJECT
public:
    CGetWebPageNews();

//    void loadWebPageNews(const QString& webSite);

//public slots:
//    void on_webPageLoadFinished(bool res);

//signals:
//    void newsLoadFinished(QString webSite, QStringList newsList);

//private:
//    QWebView* m_webView;
};

#endif // CGETWEBPAGENEWS_H
