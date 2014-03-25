#include "CNewsListWidget.h"
#include "ui_CNewsListWidget.h"
#include "CWebSiteItemDelegate.h"
#include "CNewsViewStyle.h"
#include "CWebNewsLoader.h"
#include <QTreeWidgetItem>
#include <QStringList>

CNewsListWidget::CNewsListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CNewsListWidget)
{
    ui->setupUi(this);
//    CWebSiteItemDelegate* webItemDelegate = new CWebSiteItemDelegate(this);
//    ui->listView_webSite->setItemDelegate(webItemDelegate);

    CNewsViewStyle* newsStyle = new CNewsViewStyle;
    ui->treeWidget->setStyle(newsStyle);
    //m_newsItemsModel = new QAbstractTableModel(this);
    //ui->treeView->setModel(m_newsItemsModel);


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

    ui->listWidget->addItem("http://www.guokr.com/");
}

CNewsListWidget::~CNewsListWidget()
{
    delete ui;
}

void CNewsListWidget::on_Btn_update_clicked()
{
    for (int i = 0; i < ui->listWidget->count(); i++)
    {
        QString webSite = ui->listWidget->item(i)->text();
        CWebNewsLoader* newLoader = new CWebNewsLoader;
        connect(newLoader, SIGNAL(newsLoadFinished(QString,QStringList)), SLOT(on_newsLoadFinished(QString,QStringList)));
        newLoader->loadWebPageNews(webSite);
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
