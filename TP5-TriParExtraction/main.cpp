#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define N 25
#define MAX 100

unsigned short tab[N];

int main()
{
    cout << "Tri par extraction" << endl;

    // Initialiser le générateur avec le temps comme graine
    srand(time(NULL));
    for(int i=0; i<N; i++){
        // Initialiser avec un nombre aléatoire
        tab[i]=rand()%MAX;
    }
    for(int i=0; i<N; i++){
        // Affichage du tableau
        cout << tab[i] << " ";
    }

    cout << endl << endl;

    // Tri des nombres
    for(int k=0; k<N; k++){
        int idx=k+1;
        for(int i=k+1; i<N; i++){
            if(tab[idx]>tab[i])
                idx=i;
        }
        // Permutation des valeurs
        unsigned short tmp=tab[idx];
        tab[idx]=tab[k];
        tab[k]=tmp;

    }
    for(int i=0; i<N; i++){
        // Affichage du tableau
        cout << tab[i] << " ";
    }

    cout << endl << endl;
    return 0;
}
