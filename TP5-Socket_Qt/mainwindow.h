#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTcpSocket socket;
    QLineEdit edtCamIP;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void onConnected();
    void on_actionLight_triggered(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
