#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define PIPE "PIPO"

int main(){

        int idpipe;
        idpipe = open(PIPE, O_WRONLY);

        if(idpipe<0){
                perror("erreur ouverture tube");
                exit(1);
        };

        write(idpipe,"Hello consommateur \n",10);

        long int fpc=fpathconf(idpipe, _PC_PIPE_BUF);
        printf("%ld", fpc);
        close(idpipe);
        return 0;
}
