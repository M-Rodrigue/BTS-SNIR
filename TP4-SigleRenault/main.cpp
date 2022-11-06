#include <iostream>

using namespace std;

// define | W | Nombre de caractères de large par branche
#define W 15
// define | H | Nombre de lignes de la demi-hauteur, ligne centrale comprise
#define H 21

int main()
{
    // int | maxEspace | Nombre d'espaces de tête
    int maxEspace = (80-W)/2;

    // int | lg | Ligne
    for(int lg=0; lg<H; lg++){
        // int | maxPlus | Ligne fois deux
        int maxPlus = 2*lg;
        if(maxPlus>W){
            maxPlus=W;
        }
        // int | col | Colonne
        for(int col=0; col<maxEspace; col++){
            cout << " ";
        }
        for(int col=0; col<W; col++){
            cout << "#";
        }
        for(int col=0; col<2*lg-W; col++){
            cout << " ";
        }
        for(int col=0; col<maxPlus; col++){
            cout << "+";
        }
        cout << endl;
        maxEspace--;
    }
    maxEspace += 2;
    for(int lg=H-2; lg>=0; lg--){
        int maxPlus = 2*lg;
        if(maxPlus>W){
            maxPlus=W;
        }
        for(int col=0; col<maxEspace; col++){
            cout << " ";
        }
        for(int col=0; col<W; col++){
            cout << "#";
        }
        for(int col=0; col<2*lg-W; col++){
            cout << " ";
        }
        for(int col=0; col<maxPlus; col++){
            cout << "+";
        }
        cout << endl;
        maxEspace++;
    }
    return 0;
}
