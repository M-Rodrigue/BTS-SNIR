#include "mabase.h"
#include "ui_mabase.h"

#include <QMessageBox>
#include <QDebug>
#include <QScrollBar>
#include <QPaintEvent>

MaBase::MaBase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaBase)
{
    ui->setupUi(this);
    tableModel= 0;
    queryModel = 0;
    db= QSqlDatabase::addDatabase("QMYSQL","Login");
    db.setDatabaseName("MaBase");
    db.setHostName("172.22.18.4");
    db.setUserName("MaBase");
    db.setPassword("root");
    if(!db.open())
        QMessageBox::critical(this,"Attention","Problème d'accès",QMessageBox::Ok);
    else
        qDebug()<<"MaBase ouverte";
    ui->mainToolBar->insertWidget(0,&selNom);
}

MaBase::~MaBase()
{
    delete tableModel;
    if(db.isOpen())
        db.close();
    delete ui;
}

void MaBase::on_actionRafraichir_triggered()
{
    if(selNom.text().isEmpty())
    {
        if(tableModel)
            delete tableModel;
        tableModel= new QSqlTableModel(this,db);
        tableModel->setTable("login");
        tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        if(tableModel->select())
            ui->tableView->setModel(tableModel);
        tableModel->setHeaderData(1, Qt::Horizontal, "Nom");
    }
    else
    {
        if(queryModel)
            delete queryModel;
        queryModel= new QSqlQueryModel(this);
        queryModel->setQuery("SELECT * FROM login WHERE user LIKE '"+selNom.text()+"%'",db);
        ui->tableView->setModel(queryModel);
    }
     ui->tableView->hideColumn(0);
     ui->tableView->hideColumn(3);
}

void MaBase::paintEvent(QPaintEvent *)
{
    int w= ui->tableView->width()-ui->tableView->verticalHeader()->width()
            -ui->tableView->verticalScrollBar()->width();
    ui->tableView->setColumnWidth(1,w/2);
    ui->tableView->setColumnWidth(2,w/2);
}
