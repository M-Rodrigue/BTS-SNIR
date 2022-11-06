/* Includes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Entêtes Linux */
#include <fcntl.h>     /* Contains file controls like O_RDWR */
#include <errno.h>     /* Error integer and strerror() function */
#include <termios.h>   /* Contains POSIX terminal control definitions */
#include <unistd.h>    /* write(), read(), close() */

/* Configuration */
#define douchette "/dev/ttyS4"
int tty;

/* Ouverture communication douchette */
int tty_open(char* tty_dev){

    // Assignation de l'ouverture du port série en lecture à la variable tty
    tty = open(tty_dev, O_RDWR);

    // Si la variable tty n'arrive pas à se connecter alors le programme s'arrête avec une erreur
    if(tty<0){
        printf ("Impossible d'établir la communication avec la douchette %s \n",douchette);
        return EXIT_FAILURE;
    }

    return tty;
}

void tty_close(int tty){
    close(tty);
}

int main(int argc, char **argv){
    long long dataBase[4] = {5053990162765, 3174780000363, 8000500359556, 3597610408137};
    printf("Système de caisse automatique\n");
    unsigned char buf[256];

    tty = tty_open(douchette);
    read(tty, buf, 256);
    for(int i = 0; i<4; i++){
            sleep(5);
            if(dataBase[0] == *buf){
                printf("Pringles \n");
            }
            if(dataBase[1] == *buf){
                printf("Coca cola \n");
            }
            if(dataBase[2] == *buf){
                printf("Raffaello \n");
            }
            if(dataBase[3] == *buf){
                printf("Quick \n");
            }
    }

    return 0;
}
