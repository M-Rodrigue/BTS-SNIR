/********************************************************************************
** Form generated from reading UI file 'mabase.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MABASE_H
#define UI_MABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaBase
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MaBase)
    {
        if (MaBase->objectName().isEmpty())
            MaBase->setObjectName(QStringLiteral("MaBase"));
        MaBase->resize(400, 300);
        menuBar = new QMenuBar(MaBase);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MaBase->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MaBase);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MaBase->addToolBar(mainToolBar);
        centralWidget = new QWidget(MaBase);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MaBase->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MaBase);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MaBase->setStatusBar(statusBar);

        retranslateUi(MaBase);

        QMetaObject::connectSlotsByName(MaBase);
    } // setupUi

    void retranslateUi(QMainWindow *MaBase)
    {
        MaBase->setWindowTitle(QApplication::translate("MaBase", "MaBase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MaBase: public Ui_MaBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MABASE_H
