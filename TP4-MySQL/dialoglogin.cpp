#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include "qdebug.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <qmessagebox.h>

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_buttonBox_accepted()
{
    int accepted = QDialog::Rejected;
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","Login");
        db.setDatabaseName("MaBase");
        //db.setPort(3306);
        db.setHostName("172.22.18.4");
        db.setUserName("MaBase");
        db.setPassword("root");

        if(db.open()){
            qDebug()<<"MaBase ouverte";
            QString user= ui->lineEditUser->text(); //lecture du lineEdit user
            QString password = ui->lineEditPassword->text();
            QSqlQuery query(db);
            if(!query.exec("SELECT password,id_login ... '"+user+"'")){
                QMessageBox::critical(this,"Attention","Problème requête",QMessageBox::Ok);
            } else {
                while(query.next()){
                    qDebug()<<query.value(0);
                    if(query.value(0).toString()==password){
                        accepted= QDialog::Accepted;
                        break;
                    }
                }
            }
            db.close();
        } else {
            QMessageBox::critical(this,"Attention","Problème d'accès",QMessageBox::Ok);
        }
    }
    QSqlDatabase::removeDatabase("Login");

    done(accepted);
}
