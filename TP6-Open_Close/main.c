#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char image[20][20];

/* Placer un point sur l'image
 * (x, y) coordonnées du point
 * state : 0 place un espace sinon une étoile
*/
void image_point(int x, int y, int state){
    if(state==0){
        image[x][y]=' ';
    } else {
        image[x][y]='*';
    }
}

/* Remplissage d'espace du tableau avec la fonction image_point */
void image_efface(void){
    int x, y;
    for(y=0; y<20; y++){
        for(x=0; x<20; x++){
            image_point(x,y,0);
        }
    }
    return;
}

/* Visualise le contenu de l'image */
void image_affiche(void){
    int x, y;
    for(y=0; y<20; y++){
        for(x=0; x<20; x++){
            printf ("%c",image[x][y]);

        }
        printf ("\n");
    }
}

/* Ligne horizontale */
void image_ligne_h(int x, int y, int nb_pix){
    int i = 0;

    do {
        image_point(x+i,y,1);
        i++;
    } while(i<nb_pix);
    return;
}

/* Ligne verticale */
void image_ligne_v(int x, int y, int nb_pix){
    int i = 0;

    do {
        image_point(x,y=i,1);
        i++;
    } while(i<nb_pix);
    return;
}

/* Création fichier.txt image ASCII */
void image_ecrire(void){
    int fd;

    // Droits création utilisateur/groupe/others lecture écriture
    fd = open("fichier.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(fd==-1){
        printf("Erreur avec la fonction open \n");
        exit (EXIT_FAILURE);
    }
    write(fd, "Bonjour le monde \n", 17);
    close(fd);
    return;
}

int main(){
    image_efface();
    image_point(4,4,1);

    image_ligne_h(4,4,4);
    image_ligne_v(5,4,4);

    image_affiche();
    image_ecrire();

    return EXIT_SUCCESS;
}
