#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT




public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QUdpSocket  socket;
    QString myIP,myPort, destIP,destPort;
    //Pour test des méthodes
    QHostAddress valAddr;

private slots:
    void slot_send_action();
    void slot_onReadyRead();
    void slot_exit_action();
    void on_actionSend_triggered();
    void on_actionExit_triggered();
};
#endif // MAINWINDOW_H
