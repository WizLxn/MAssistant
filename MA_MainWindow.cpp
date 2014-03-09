#include "MA_MainWindow.h"
#include "ui_MA_MainWindow.h"

MA_MainWindow::MA_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MA_MainWindow)
{
    ui->setupUi(this);
}

MA_MainWindow::~MA_MainWindow()
{
    delete ui;
}
