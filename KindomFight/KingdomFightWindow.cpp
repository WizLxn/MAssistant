#include "KingdomFightWindow.h"
#include "ui_KingdomFightWindow.h"
#include "DataBase/KFDataBase.h"

KingdomFightWindow::KingdomFightWindow(KFDataBase *database, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KingdomFightWindow),
    m_dbConn(database)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose);
}

KingdomFightWindow::~KingdomFightWindow()
{
    delete ui;
}

void KingdomFightWindow::showTextMessage(const QString &strMsg)
{
    ui->textBrowser->append(strMsg);
}
