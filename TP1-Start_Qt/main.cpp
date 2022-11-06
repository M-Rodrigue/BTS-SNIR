#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
    //cout<<"Hello World!" << endl;

    //Print "Crée à vie !"
    cout<<"Cr\202e \x85 vie !" << endl;

    //Wainting action of user
    while (!kbhit()) {
        cout<<"\r /";
        Sleep(50); //Wait 50ms
        cout<<"\r -";
        Sleep(50);
        cout<<"\r \\";
        Sleep(50);
        cout<<"\r |";
        Sleep(50);
    }

    getch();

    //Wainting action of user
    while (!kbhit()) {
        cout<<"\r \\";
        Sleep(50); //Wait 50ms
        cout<<"\r -";
        Sleep(50);
        cout<<"\r /";
        Sleep(50);
        cout<<"\r |";
        Sleep(50);
    }

    getch();

    while (!kbhit()) {
        cout<<"=";
        Sleep(500);
        cout<<"=";
        Sleep(500);
        cout<<"=";
        Sleep(500);
        cout<<"=";
        Sleep(500);
        cout<<"=";
        Sleep(500);
        cout<<"=";
        Sleep(500);
        cout<<"\r Is installed (100%)";
        Sleep(1000);
        break;
    }
    return 0;
}
