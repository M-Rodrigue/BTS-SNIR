#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHostAddress>
#include <QNetworkProxy>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    edtCamIP.setText("172.22.49.194");
    ui->mainToolBar->insertWidget(0, &edtCamIP);
    socket.setProxy(QNetworkProxy::NoProxy);
    connect(&socket, SIGNAL(connected()), SLOT(onConnected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QHostAddress address = QHostAddress(edtCamIP.text());
    socket.connectToHost(address,80);
}

void MainWindow::onConnected()
{
    statusBar()->showMessage("Connecté !", 3000);
}

void MainWindow::on_actionLight_triggered(bool checked)
{
    QByteArray msg;
    if(checked){
        msg = "GET /axis-cgi/io/lightcontrol.cgi?action=L1:-100 HTTP/1.1\r\n\r\n";
    } else {
        msg = "GET /axis-cgi/io/lightcontrol.cgi?action=L1:-0 HTTP/1.1\r\n\r\n";
    }

    socket.write(msg);
}
