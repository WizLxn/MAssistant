#include "CWebNewsLoader.h"
#include <QWebView>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElementCollection>
#include <QTextStream>
#include <QFile>
#include <QEventLoop>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include <QDir>
#include <QXmlDefaultHandler>
#include <QDomDocument>

CWebNewsLoader::CWebNewsLoader(QObject *parent) :
    QObject(parent)
{
}

void CWebNewsLoader::loadWebPageNewsList(const QString &webSite)
{
        m_webView = new QWebView;
        m_webView->load(webSite);
        QObject::connect(m_webView, SIGNAL(loadFinished(bool)), SLOT(on_webPageLoadFinished(bool)));
}

void CWebNewsLoader::loadRssNewsList(const QString& webSite)
{
    if (webSite.isEmpty())
        return;

    QEventLoop loop;
    QNetworkReply *reply = manager->get(QNetworkRequest(sUrl));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();


    QFile file(QDir::tempPath() + "MAssistant/newList.xml");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out.setCodec("UTF8");
    QTextCodec *codec = QTextCodec::codecForName("UTF8");
    out << codec->toUnicode(reply->readAll()) << endl;
    file.close();


    QFile xmlfile(file);
     if(!xmlfile.open(QFile::ReadOnly | QFile::Text))
         return;
     QTextStream floStream(&xmlfile);
     //QTextCodec *codec = QTextCodec::codecForName("UTF8");
     floStream.setCodec(codec);
     QString xmlData = floStream.readAll();
     xmlfile.close();
    QDomDocument doc;

    if(doc.setContent(xmlData))
    {

    }
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

            emit newsListLoadFinished(m_webView->url().toString(), newsList);
        }

        m_webView->deleteLater();
        deleteLater();
}
