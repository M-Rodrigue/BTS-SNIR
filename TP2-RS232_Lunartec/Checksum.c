#include <stdio.h>
#include <stdlib.h>

int main (int argc,char **argv){

	int i=0;
	int cs=0;

	if (argc!=2){
		printf("Veuillez rentrer un argument \n");
        	return (EXIT_FAILURE);
	}

	while (argv[1][i]!=0){
		/* CS avec des ou exclusif */
		cs=(argv[1][i++])^cs;
	 }

	printf("%x\n",cs);

return (EXIT_SUCCESS);
}
