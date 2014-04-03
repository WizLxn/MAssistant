#include "CInfoEditor.h"
#include "ui_CInfoEditor.h"
#include <QToolBar>
#include <QAction>

CInfoEditor::CInfoEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CInfoEditor)
{
    ui->setupUi(this);
    setGeometry(0, 0, 1000 ,650);
    connect(ui->widget, SIGNAL(showItemText(QString, QString)), SLOT(displayItemInfo(QString, QString)));
}

CInfoEditor::~CInfoEditor()
{
    delete ui;
}

void CInfoEditor::displayItemInfo(QString strTitle, QString strText)
{
    ui->lineEdit->setText(strTitle);
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setText(strText);
}

void CInfoEditor::initToolBar()
{
    QToolBar* toolBar = addToolBar("&File");
    m_actionAddItem = new QAction(tr("Add Item"), toolBar);
}
