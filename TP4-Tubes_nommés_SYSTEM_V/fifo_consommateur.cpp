#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define PIPE "PIPO"

int main()
{
        if(mkfifo(PIPE, 0750)){
                perror("erreur creation tube");
                exit(1);
        };

        int idpipe;
        char buf[11];
        idpipe = open(PIPE, O_RDONLY);

        if(idpipe<0){
                perror("erreur ouverture tube");
                exit(2);
        };

        read(idpipe,buf,10);

        long int fpc = fpathconf(idpipe, _PC_PIPE_BUF);
        printf("%ld", fpc);

        buf[10] =0;
        printf("Reception : %s",buf);
        close(idpipe);
        return 0;
}
