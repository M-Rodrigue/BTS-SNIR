#include <iostream>
#include "libaff7seg.h"
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    cout << "Afficheur 7 segments" << endl;
    aff7segInit(4);

    // Exercice "HELP"
    aff7segSet(0,0x76); // Lettre "H"
    aff7segSet(1,0x79); // Lettre "E"
    aff7segSet(2,0x38); // Lettre "L"
    aff7segSet(3,0x73); // Lettre "P"

    Sleep(2000);

    // Afficheur "Err"
    aff7segSet(0,0x79); // Lettre "E"
    aff7segSet(1,0x50); // Lettre "r"
    aff7segSet(2,0x50); // Lettre "r"
    aff7segSet(3,0x00); // rien

    Sleep(2000);

    aff7segSet(0,0x00); // rien
    aff7segSet(1,0x00); // rien
    aff7segSet(2,0x00); // rien
    aff7segSet(3,0x00); // rien

    // Indication de chargement
    while(!kbhit()){
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        Sleep(200);
        aff7segSet(0,0x00); // rien
        aff7segSet(1,0x00); // rien
        aff7segSet(2,0x00); // rien
        aff7segSet(3,0x00); // rien
        Sleep(200);
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        Sleep(200);
        aff7segSet(0,0x00); // rien
        aff7segSet(1,0x00); // rien
        aff7segSet(2,0x00); // rien
        aff7segSet(3,0x00); // rien
        Sleep(200);
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        Sleep(200)
        aff7segSet(0,0x00); // rien
        aff7segSet(1,0x00); // rien
        aff7segSet(2,0x00); // rien
        aff7segSet(3,0x00); // rien
        Sleep(200);
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        aff7segSet(0,0x01); // - haut
        Sleep(200)
        Sleep(200);
    }

/*
    // Changement de vitesse
    int count = 1;
    int delai = 200;

    while(!kbhit()){
        aff7segSet(0,0x01); // - haut
        Sleep(delai);
        aff7segSet(0,0x00); // rien
        aff7segSet(1,0x01); // - haut
        Sleep(delai);
        aff7segSet(1,0x00); // rien
        aff7segSet(2,0x01); // - haut
        Sleep(delai);
        aff7segSet(2,0x00); // rien
        aff7segSet(3,0x01); // - haut
        Sleep(delai);
        aff7segSet(3,0x00); // rien
        aff7segSet(3,0x02); // - droit
        Sleep(delai);
        aff7segSet(3,0x00); // rien
        aff7segSet(3,0x04); // - droit
        Sleep(delai);
        aff7segSet(3,0x00); // rien
        aff7segSet(3,0x08); // - bas
        Sleep(delai);
        aff7segSet(3,0x00); // rien
        aff7segSet(2,0x08); // - bas
        Sleep(delai);
        aff7segSet(2,0x00); // rien
        aff7segSet(1,0x08); // - bas
        Sleep(delai);
        aff7segSet(1,0x00); // rien
        aff7segSet(0,0x08); // - bas
        Sleep(delai);
        aff7segSet(0,0x00); // rien
        aff7segSet(0,0x10); // - droit
        Sleep(delai);
        aff7segSet(0,0x00); // rien
        aff7segSet(0,0x20); // - droit
        Sleep(delai);
        aff7segSet(0,0x00); // rien


        if(count==3){
            if(delai==200){
                delai = 100;
            } else {
                delai = 200;
            }
        count = 1;
        } else {
            count++;
        }
    }
*/

    return 0;
}

