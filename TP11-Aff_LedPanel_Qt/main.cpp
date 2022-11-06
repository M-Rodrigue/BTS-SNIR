#include <iostream>
#include "libLedPanel.h"

using namespace std;
extern unsigned char Police5x7[][7];

void smile(int x, int y);
void ledPanelCar(int x, int y, char car, bool inverse=false);
void ledPanelText(int x, int y, char text[], bool inverse=false);

int main()
{
    cout << "Led Panel" << endl;
    ledPanelInit(128,32);
    for(int i=0; i<8; i++){
        ledPanelSetColor(i);
        smile(10+i*10, 10);
    }
    ledPanelCar(20,20,'A', false);
    ledPanelText(50, 20, "Bonjour", false);
    return 0;
}

void ledPanelText(int x, int y, char text[], bool inverse){
    for(int i=0;text[i]!=0;i++){
        ledPanelCar(+i*6,y,text[i], inverse);
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


