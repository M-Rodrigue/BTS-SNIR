#ifndef MABASE_H
#define MABASE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QLineEdit>

namespace Ui {
class MaBase;
}

class MaBase : public QMainWindow
{
    Q_OBJECT
    QSqlDatabase db;
    QSqlTableModel *tableModel;
    QSqlQueryModel *queryModel;
    QLineEdit selNom;


public:
    explicit MaBase(QWidget *parent = 0);
    ~MaBase();
    void paintEvent(QPaintEvent *);

private slots:
    void on_actionRafraichir_triggered();

private:
    Ui::MaBase *ui;
};

#endif // MABASE_H
