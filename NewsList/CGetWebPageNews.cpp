#include "CGetWebPageNews.h"
#include <QStringList>
#include <QWebView>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElementCollection>

//void CGetWebPageNews::loadWebPageNews(const QString &webSite)
//{
//    m_webView = new QWebView;
//    m_webView->load(webSite);
//    QObject::connect(m_webView, SIGNAL(loadFinished(bool)), SLOT(on_webPageLoadFinished(bool)));
//}

//void CGetWebPageNews::on_webPageLoadFinished(bool res)
//{
//    if (res)
//    {
//        QWebFrame *frame = m_webView->page()->mainFrame();

//        QWebElement document = frame->documentElement();
//        QWebElementCollection elements = document.findAll("li");

//        QStringList newsList;
//        foreach (QWebElement element, elements)
//            newsList.append(element.toPlainText());

//        emit newsLoadFinished(m_webView->url().toString(), newsList);
//    }

//    deleteLater();
//}



CGetWebPageNews::CGetWebPageNews()
{

}
