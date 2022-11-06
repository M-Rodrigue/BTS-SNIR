#include <stdlib.h>
#include <stdio.h>

int main(int argc, char  **argv)
{
	long int masque=0x0001;
	int  valeur;
	int compteur;

	if (argc==2){
        	valeur=atoi(argv[1]);
        	for (compteur=0; compteur <= 16 ; compteur ++){
        		if (valeur & (masque<<compteur))  printf("1");
        		else printf ("0");
   		}
		printf("\n");
	} else return EXIT_FAILURE;

return EXIT_SUCCESS;
}
