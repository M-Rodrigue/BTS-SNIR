#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connexion entre SIGNAL et SLOT
    connect( &socket, SIGNAL(readyRead()), this, SLOT(slot_onReadyRead()) );

    myPort="7755";
    myIP="127.0.0.10";

    destIP="127.0.0.20";
    destPort="62714";

    //Création de la socket avec bind
    //bool ok=socket.bind(QHostAddress(myIP),7755);
    //bool ok=socket.bind(QHostAddress::LocalHost,myPort.toUInt());

    valAddr.setAddress(myIP);

    bool ok=socket.bind(valAddr,myPort.toUShort());
    if( ok )
    {
        qDebug() << "Création de la socket-> bind=" << ok << endl;
        //qDebug() << "IP=" << QHostAddress::LocalHost << "Port=" << myPort << endl;
        qDebug() << "IP=" << myIP << "Port=" << myPort << endl;
    }
    else qDebug() << "Echec de bind" << endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_send_action()
{
    /*
    qDebug() << "Action Send cliquée" << endl;
    //Ecriture de l'émission d'une trame en UDP par writeDatagram
    QHostAddress adresse("127.0.0.20");
    QByteArray datagram="hello du client UDP";
    socket.writeDatagram(datagram.data(), datagram.size(), adresse, 4210);
    qDebug() << "Emission de" << datagram << "vers" << adresse << "Port=" << 4210 << endl;
    */

    qDebug() << "Action Send cliquée" << endl;
    //Ecriture de l'émission d'une trame en UDP par writeDatagram
    //Acquisition depuis le TextEdit
    //Test si changement : insertion ou delete
    //Faire avec textChanged() qui est un Signal

    //Tout le text entré au clavie
    //"\n" pour aller à la ligne
    QString monText = ui->textEdit->toPlainText()+"\n";



    QHostAddress adresse(destIP);
    bool Done;
    quint16 port=destPort.toUShort(&Done);
    if(!Done) {
                qDebug() << "Erreur de port" << endl;
                            return;
              }

    QByteArray datagram=monText.toLatin1();
    if( (socket.writeDatagram(datagram.data(), datagram.size(), adresse, port)) != monText.length() )
    {
        qDebug() << "Erreur dans l'emission de " << datagram << "vers" << adresse << "Port=" << port << endl;
        //Report de cette erreur dans le TextEdit
        ui->textEdit->clear();
        ui->textEdit->append("Erreur dans writeDatagram");
    }
    else
    qDebug() << "Emission de" << datagram << "vers" << adresse << "Port=" << port << endl;

}

void MainWindow::slot_exit_action()
{
    close();
    qDebug() << "Action Exit cliquée" << endl;
}

void MainWindow::slot_onReadyRead()
{
    qDebug() << "Données reçues à lire" << endl;

    statusBar()->showMessage("lecture de données",3000);

    QHostAddress sender;
    quint16 port;
    while(socket.hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(socket.pendingDatagramSize());
        socket.readDatagram(datagram.data(),datagram.size(),&sender,&port);

        //Affichage dans le TextEdit
        //QString s(datagram);
        QString datas=QString(datagram);
        quint32 ad32= sender.toIPv4Address();
        sender.setAddress(ad32);
        ui->textEdit->append(datas.toUtf8()+"  ("+sender.toString()+"/"+QString::number(port)+")");

        qDebug() << " Message de =" << sender.toString() << endl;
        qDebug() << " Port= " << port << endl;
        qDebug() << " Data= " << datagram << endl;
    }


}

void MainWindow::on_actionSend_triggered()
{
    /*
    qDebug() << "Action Send cliquée" << endl;
    //Ecriture de l'émission d'une trame en UDP par writeDatagram
    QHostAddress adresse("127.0.0.20");
    QByteArray datagram="hello du client UDP";
    socket.writeDatagram(datagram.data(), datagram.size(), adresse, 4210);
    qDebug() << "Emission de" << datagram << "vers" << adresse << "Port=" << 4210 << endl;
    */

    qDebug() << "Action Send cliquée" << endl;
    //Ecriture de l'émission d'une trame en UDP par writeDatagram
    //Acquisition depuis le TextEdit
    //Test si changement : insertion ou delete
    //Faire avec textChanged() qui est un Signal

    //Tout le text entré au clavie
    //"\n" pour aller à la ligne
    QString monText = ui->textEdit->toPlainText()+"\n";



    QHostAddress adresse(destIP);
    bool Done;
    quint16 port=destPort.toUShort(&Done);
    if(!Done) {
                qDebug() << "Erreur de port" << endl;
                            return;
              }

    QByteArray datagram=monText.toLatin1();
    if( (socket.writeDatagram(datagram.data(), datagram.size(), adresse, port)) != monText.length() )
    {
        qDebug() << "Erreur dans l'emission de " << datagram << "vers" << adresse << "Port=" << port << endl;
        //Report de cette erreur dans le TextEdit
        ui->textEdit->clear();
        ui->textEdit->append("Erreur dans writeDatagram");
    }
    else
    qDebug() << "Emission de" << datagram << "vers" << adresse << "Port=" << port << endl;
}

void MainWindow::on_actionExit_triggered()
{

    close();
    qDebug() << "Action Exit cliquée" << endl;
}
