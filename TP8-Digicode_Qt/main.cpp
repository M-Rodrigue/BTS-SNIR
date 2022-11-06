#include <iostream>
#include <conio.h>
#include <windows.h>
#include "libDigicode.h"

using namespace std;

int numBit(int valeur);
int scrutDigicode();
int transcode(int index);
void saisieCode(int code[]);
bool testCode(int code[]);

int main()
{
    digicodeInit();
    cout << "Scrutation" << endl;
    cout << numBit(0x560);
    int code[4];
    saisieCode(code);
    for(int i=0; i<4; i++){
        cout << code[i] << " ";
    }
    cout << endl;
    if(testCode(code)){
        cout << "OK" << endl;
        return 0;
    }

    while(!kbhit()){
        cout << transcode(scrutDigicode()) << " \r";
        //int ligne = digicodeRead(2);
        //cout << ligne << "\r";
        Sleep(100);
    }

    return 0;
}

int scrutDigicode(){
    int index = -1;
    for(int colonne=1; colonne<8; colonne=colonne<<1){
        int ligne = digicodeRead(colonne);
        if(ligne!=0){
            //cout << ligne << colonne << endl;
            index = numBit(colonne) << 2 | numBit(ligne);
            break;
        }
    }
    return index;
}

int numBit(int valeur){
    int indexBit;

    for(indexBit=0; indexBit<32; indexBit++){
        if((valeur&1)!=0){
            break;
        } else {
            valeur = valeur >> 1;
        }
    }

    return indexBit;
}

int transcode(int index){
    if(!(index <= 11 && index >= 0)){
        return -1;
    }
    int tab[12] = {1, 4, 7, 10, 2, 5, 8, 0, 3, 6, 9, 11};
    return tab[index];
}

void saisieCode(int code[]){
    for(int numTouche=0; ; ){
        int index;
        do{
            index = scrutDigicode();
        }
        while(index==1);
        code[numTouche] = transcode(index);
        while(scrutDigicode()!=-1);
    }
}

bool testCode(int code[]){
    int codeSecret[] = {1, 2, 3, 4};
    for(int i=0; i<4; i++){
        if(code[i]!=codeScret[i]){
            return false;
        }
        return true;
    }
}
