#include <stdio.h>
#include <stdlib.h>

/****************************************
**  CODE PERMETTANT DE TESTER le BIT 6 **
**  Bogt 16/12/2020                    **
*****************************************/

int main(int argc,char **argv)
{
    int nombre;

    if (argc!=2)
    {
        printf ("Veuillez mettre un argument \n");
        return EXIT_FAILURE;
    }

    nombre=atoi(argv[1]);

    if (nombre & 1<<6){
        printf("il est a 1 \n");
    } else {
        printf("il est a 0 \n");
    }

    return EXIT_SUCCESS;
}
