#ifndef MABASE_H
#define MABASE_H

#include <QMainWindow>

namespace Ui {
class MaBase;
}

class MaBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit MaBase(QWidget *parent = 0);
    ~MaBase();

private:
    Ui::MaBase *ui;
};

#endif // MABASE_H
