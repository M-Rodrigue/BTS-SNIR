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

void MainWindow::RGBAdjust()
{
    int r = ui->spinBoxR->value();
    int g = ui->spinBoxG->value();
    int b = ui->spinBoxB->value();
    QPalette pal;
    pal.setColor(QPalette::Window, QColor(r, g, b));
    pal.setColor(QPalette::WindowText, QColor(255, 255, 255));
    ui->labelRGB->setPalette(pal);
}

void MainWindow::on_spinBoxR_valueChanged(int val)
{

    QPalette pal;
    pal.setColor(QPalette::Base, QColor(val, 0, 0));
    pal.setColor(QPalette::Text, QColor(255, 255, 255));
    ui->spinBoxR->setPalette(pal);
    RGBAdjust();
}

void MainWindow::on_spinBoxG_valueChanged(int val)
{

    QPalette pal;
    pal.setColor(QPalette::Base, QColor(0, val, 0));
    pal.setColor(QPalette::Text, QColor(255, 255, 255));
    ui->spinBoxG->setPalette(pal);
    RGBAdjust();
}

void MainWindow::on_spinBoxB_valueChanged(int val)
{

    QPalette pal;
    pal.setColor(QPalette::Base, QColor(0, 0, val));
    pal.setColor(QPalette::Text, QColor(255, 255, 255));
    ui->spinBoxB->setPalette(pal);
    RGBAdjust();
}

void MainWindow::on_listColor_clicked(const QModelIndex &index)
{
    QColor c(index.data().toString());
    ui->spinBoxR->setValue(c.red());
    ui->spinBoxG->setValue(c.green());
    ui->spinBoxB->setValue(c.blue());
}
