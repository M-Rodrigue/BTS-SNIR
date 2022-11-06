#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    unsigned char nombre;
    unsigned char masque;

    if (argc!=2){
        printf("Veuillez mettre un argument \n");
        return EXIT_FAILURE;
    }

    nombre = atoi(argv[1]);
    masque = 0xF0;

    printf("Masque décimal : %d \n", masque);
    printf("Masque complément décimal : %d \n", ~masque);
    printf("Masque hexadécimal : %x \n", masque);
    printf("Masque complément hexadécimal : %x \n\n", ~masque);

    printf("Nombre décimal : %d \n", nombre);
    printf("Nombre complément décimal : %d \n", ~nombre);
    printf("Nombre hexadécimal : %x \n", nombre);
    printf("Nombre complément hexadécimal : %x \n", ~nombre);

    return EXIT_SUCCESS;
}
