#include "maMainWindow.h"
#include "ui_maMainWindow.h"
#include <QPainter>
#include "maWindowStyle.h"

CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MA_MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setStyle(new CWindowStyle());
    //setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
}

CMainWindow::~CMainWindow()
{
    delete ui;
}

void CMainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QStyleOptionFocusRect option;
    option.initFrom(this);
    option.backgroundColor = Qt::blue;//palette().color(Qt::blue);

    //style()->drawPrimitive(QStyle::PE_FrameFocusRect, &option, &painter, this);
    painter.setBrush(Qt::blue);
    painter.drawRect(option.rect);

    QMainWindow::paintEvent(event);
}
