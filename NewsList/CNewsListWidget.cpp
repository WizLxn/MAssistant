#include "CNewsListWidget.h"
#include "ui_CNewsListWidget.h"
#include "CWebSiteItemDelegate.h"
#include "CNewsViewStyle.h"
#include "CWebNewsLoader.h"
#include "CWebSiteListModel.h"
#include <QTreeWidgetItem>
#include <QStringList>

CNewsListWidget::CNewsListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CNewsListWidget)
{
    ui->setupUi(this);

    CNewsViewStyle* newsStyle = new CNewsViewStyle;
    ui->treeWidget->setStyle(newsStyle);

    // basic features
    ui->treeWidget->header()->hide();
    ui->treeWidget->setAnimated(true);
    ui->treeWidget->setFrameStyle(QFrame::NoFrame);
    ui->treeWidget->viewport()->setAttribute(Qt::WA_AcceptTouchEvents, true);
    ui->treeWidget->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->treeWidget->setAutoFillBackground(true);
    ui->treeWidget->setTextElideMode(Qt::ElideMiddle);
    ui->treeWidget->setIndentation(12);

    QTreeWidgetItem* topLevelItem = new QTreeWidgetItem();
    topLevelItem->setData(0, Qt::DisplayRole, "Top Level Item");
    ui->treeWidget->addTopLevelItem(topLevelItem);
    QTreeWidgetItem* childItem = new QTreeWidgetItem();
    childItem->setData(0, Qt::DisplayRole, "Child Item one");
    topLevelItem->addChild(childItem);
    childItem = new QTreeWidgetItem();
    childItem->setData(0, Qt::DisplayRole, "Child Item two");
    topLevelItem->addChild(childItem);


//    CWebSiteItemDelegate* webItemDelegate = new CWebSiteItemDelegate(this);
//    ui->listView->setItemDelegate(webItemDelegate);
    m_webSiteModel = new CWebSiteListModel(ui->listView);
    ui->listView->setModel(m_webSiteModel);
    SWebSite goukr;
    goukr.enable = true;
    goukr.strUrl = "http://www.guokr.com/";
    m_webSiteModel->addWebSite(goukr);
    goukr.enable = true;
    goukr.strUrl = "http://www.36kr.com/";
    m_webSiteModel->addWebSite(goukr);
}

CNewsListWidget::~CNewsListWidget()
{
    delete ui;
}

void CNewsListWidget::on_Btn_update_clicked()
{
    for (int i = 0; i < m_webSiteModel->rowCount(); i++)
    {
        SWebSite webSite;
        if (!m_webSiteModel->getWebSite(webSite, i))
            continue;

        if (!webSite.enable || webSite.strUrl.isEmpty())
            continue;

        CWebNewsLoader* newLoader = new CWebNewsLoader;
        connect(newLoader, SIGNAL(newsListLoadFinished(QString,QStringList)), SLOT(on_newsLoadFinished(QString,QStringList)));
        newLoader->loadWebPageNewsList(webSite.strUrl);
    }
}

void CNewsListWidget::on_Btn_add_clicked()
{

}

void CNewsListWidget::on_btn_edit_clicked()
{

}

void CNewsListWidget::on_Btn_delete_clicked()
{

}

void CNewsListWidget::on_Btn_OK_clicked()
{

}

void CNewsListWidget::on_newsLoadFinished(QString webSite, QStringList newsList)
{
    QTreeWidgetItem* topLevelItem = new QTreeWidgetItem();
    topLevelItem->setData(0, Qt::DisplayRole, webSite);
    ui->treeWidget->addTopLevelItem(topLevelItem);
    foreach (QString newInfo, newsList)
    {
        QTreeWidgetItem* childItem = new QTreeWidgetItem();
        childItem->setData(0, Qt::DisplayRole, newInfo);
        topLevelItem->addChild(childItem);
    }
}
