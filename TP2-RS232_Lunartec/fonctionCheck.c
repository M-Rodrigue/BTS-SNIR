#include <stdio.h>
#include <stdlib.h>

unsigned char CheckSum(char *chaine)
{
	int compteur = 0;
	unsigned char calcs = 0;

	while (chaine[compteur]!=0)
	{
        	calcs=(chaine[compteur++])^calcs;
        }
	return(calcs);

}

int main(int argc, char **argv)

{
	printf("%02x \n",CheckSum("<L0><PB><FA><Mb><WB><FB>Bonjour le monde"));
	return EXIT_SUCCESS;
}
