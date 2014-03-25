#include "CWebNewsLoader.h"
#include <QWebView>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElementCollection>

CWebNewsLoader::CWebNewsLoader(QObject *parent) :
    QObject(parent)
{
}

void CWebNewsLoader::loadWebPageNews(const QString &webSite)
{
        m_webView = new QWebView;
        m_webView->load(webSite);
        QObject::connect(m_webView, SIGNAL(loadFinished(bool)), SLOT(on_webPageLoadFinished(bool)));
}

void CWebNewsLoader::on_webPageLoadFinished(bool res)
{
        if (res)
        {
            QWebFrame *frame = m_webView->page()->mainFrame();

            QWebElement document = frame->documentElement();
            QWebElementCollection elements = document.findAll("li a");

            QStringList newsList;
            foreach (QWebElement element, elements)
                newsList.append(element.toPlainText());

            emit newsLoadFinished(m_webView->url().toString(), newsList);
        }

        deleteLater();
}
