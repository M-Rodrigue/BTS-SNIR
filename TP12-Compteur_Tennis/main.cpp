#include <iostream>
#include "libLedPanel.h"
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;
extern unsigned char Police5x7[][7];

unsigned char pacman[][8]=
{
    { 0x1C,0x38,0x70,0x60,0x70,0x38,0x1C,0 },
    { 0x1C,0x3E,0x78,0x70,0x78,0x3E,0x1C,0 },
    { 0x1C,0x3E,0x7F,0x7F,0x7F,0x3E,0x1C,0 },
    { 0x1C,0x3E,0x78,0x70,0x78,0x3E,0x1C,0 }
};

unsigned char pacmanR[][8]=
{
    { 0x38,0x1C,0x0E,0x06,0x0E,0x1C,0x38,0 },
    { 0x38,0x7C,0x1E,0x0E,0x1E,0x7C,0x38,0 },
    { 0x38,0x7C,0xFE,0xFE,0xFE,0x7C,0x38,0 },
    { 0x38,0x7C,0x1E,0x0E,0x1E,0x7C,0x38,0 }
};

unsigned char ghost[][8]=
{
    { 0x3E,0x7F,0x49,0x5B,0x7F,0x7F,0x6D,0 },
    { 0x3E,0x7F,0x49,0x5B,0x7F,0x7F,0x5B,0 },
    { 0x3E,0x7F,0x49,0x5B,0x7F,0x7F,0x36,0 }
};

unsigned char ghostR[][8]=
{
    { 0x7C,0xFE,0x92,0xDA,0xFE,0xFE,0x6C,0 },
    { 0x7C,0xFE,0x92,0xDA,0xFE,0xFE,0xDA,0 },
    { 0x7C,0xFE,0x92,0xDA,0xFE,0xFE,0xB6,0 }
};

void smile(int x, int y);
void ledPanelCar(int x, int y, char car, bool inverse=false);
void ledPanelText(int x, int y, char text[], bool inverse=false);
void ledPanelTime(int x, int y, bool date=false);
void ledPanelSprite8(int x, int y, int v, unsigned char tab[][8]);

int main()
{
    cout << "Led Panel" << endl;
    ledPanelInit(128,32);
    for(int i=0; i<8; i++){
        ledPanelSetColor(i);
        smile(10+i*10, 10);
    }
    ledPanelCar(20,20,'A', true);
    ledPanelText(50, 20, " Bonjour", true);
    ledPanelSetColor(WHITE);
    ledPanelTime(66,0,true);
    int x =0;
    while(!kbhit()){
        ledPanelTime(6,0);
        ledPanelSprite8(x,20,x%4,pacman);
        x++;

        Sleep(100);
    }
    return 0;
}

void ledPanelSprite8(int x, int y, int v, unsigned char tab[][8]){
    for(int i=0; i<7; i++){
        ledPanelSetPoint8(x,y+i,tab[v][i]);
    }
}

void ledPanelTime(int x, int y, bool date){
    static time_t tempsOld = 0;
    char text[16];
    time_t temps = time(NULL);
    if(date){
        strftime(text,sizeof(text), "%d/%m/%Y", localtime(&temps));
        ledPanelText(x,y,text);
    } else if(temps != tempsOld){
        strftime(text,sizeof(text),"%X",localtime(&temps));
        ledPanelText(x,y,text);
        tempsOld=temps;
    }
}

void ledPanelText(int x, int y, char text[], bool inverse){
    for(int i=0;text[i]!=0;i++){
        ledPanelCar(x+i*6,y,text[i], inverse);
    }
}

void smile(int x, int y){
    ledPanelSetPoint8(x,y,0x3C);
    ledPanelSetPoint8(x,y+1,0x42);
    ledPanelSetPoint8(x,y+2,0xA5);
    ledPanelSetPoint8(x,y+3,0x81);
    ledPanelSetPoint8(x,y+4,0xA5);
    ledPanelSetPoint8(x,y+5,0x99);
    ledPanelSetPoint8(x,y+6,0x42);
    ledPanelSetPoint8(x,y+7,0x3C);
}

void ledPanelCar(int x, int y, char car, bool inverse){
    car = car-' ';

    for(int i=0; i<7; i++){
        if(inverse){
            ledPanelSetPoint8(x, y+i, Police5x7[car][i]^0b11111100);
        } else {
            ledPanelSetPoint8(x, y+i, Police5x7[car][i]);
        }
        if(inverse){
            ledPanelSetPoint8(x,y+7,0b11111100);
        }
    }
}


