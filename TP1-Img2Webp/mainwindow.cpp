#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionOuvrir_triggered()
{
    QFileDialog dlg(this,"Ouvrir image","","Images (*.png *.jpg *.jpeg);;Tous fichiers (*.*)");

    if(dlg.exec()==QDialog::Accepted){
        // Affichage du nom de l'image
        QPixmap pixmap;
	pixmap.load(imageName);
	imageName= dlg.selectedFiles()[0];
    } else {
        // Affichage qu’aucune image n’est sélectionnée
        statusBar()->showMessage("Aucune image",5000);
    }
}

void MainWindow::on_actionConvertir_triggered()
{
	QString imageWebpName;
	
	// Préparation du nom de l'image avec l'extension WebP
	int idx=imageName.left(idx)+".webp";
	qDebug()<<imageWebpName;
	QStringList arguments;
	arguments<<imageName<<"-o"<<imageWebpName;
	qDebug()<<QProcess::execute("cwebp.exe",arguments);
}
