#include "CInfoEditor.h"
#include "ui_CInfoEditor.h"

CInfoEditor::CInfoEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CInfoEditor)
{
    ui->setupUi(this);
}

CInfoEditor::~CInfoEditor()
{
    delete ui;
}
