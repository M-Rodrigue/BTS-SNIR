/********************************/
/* Donne la taille des types	  */
/********************************/

#include <stdlib.h>   /* librairie standard C prototype */
#include <stdio.h>    /* library standard Input/Output */

/* sizeof donne la taille en bytes de son opérande */

int main(int argc, char **argv){
  printf("Les tailles de variables en octets : \n");
  printf("char         : %d\n",sizeof(char));
  printf("short        : %d\n",sizeof(short));
  printf("int          : %d\n",sizeof(int));
  printf("long         : %d\n",sizeof(long));
  printf("int long     : %d\n",sizeof(int long));
  printf("float        : %d\n",sizeof(float));
  printf("double       : %d\n",sizeof(double));
  return EXIT_SUCCESS;
}