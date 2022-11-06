#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    unsigned char nombre;
    unsigned char masque;

    if (argc!=2){
        return EXIT_FAILURE;
    }

    nombre = atoi(argv[1]);
    masque = 0xF0;

    printf("Nombre en décimal : %d \n", nombre);
    printf("Nombre en hexadécimal : %x \n", nombre);

    return EXIT_SUCCESS;
}
