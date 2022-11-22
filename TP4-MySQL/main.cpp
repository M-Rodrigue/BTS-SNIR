#include "dialoglogin.h"
#include "mabase.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogLogin dlg; // Création de la boite de dialogue
    if(dlg.exec()){// affichage
        MaBase w; // Création de la fenêtre principale
        w.show(); // Affichage
        return a.exec();// exécution de l'application
    } else {
        QMessageBox::critical(0,"Erreur","Problème d'authentification");
        return 0;
    }

    MaBase w;
    w.show();

    return a.exec();
}
