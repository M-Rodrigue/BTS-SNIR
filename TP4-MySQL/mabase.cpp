#include "mabase.h"
#include "ui_mabase.h"

MaBase::MaBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaBase)
{
    ui->setupUi(this);
}

MaBase::~MaBase()
{
    delete ui;
}
