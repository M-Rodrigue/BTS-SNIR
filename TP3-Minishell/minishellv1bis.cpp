#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
        while(1){
                printf("Entrez votre commande \n");
                char LnCmd[1024];
                fgets(LnCmd,1024,stdin);
                LnCmd[strlen(LnCmd)-1] = 0;

                pid_t pid;
                pid = fork ();

                switch(pid){
                        case 0:
                                /* Processus fils */
                                printf("enfant %s \n", LnCmd);
                                return execlp( LnCmd, LnCmd, NULL);
                                perror("Erreur de execlp");
                                exit(22);
                        break;

                        case -1:
                                /* Traitement d'erreur */
                                perror("Erreur de fork");
                        break;

                        default:
                                /* Processus père */
                                printf("papa %s \n",LnCmd);
                                int status;
                                wait(&status);
                                printf("%04X %d \n", status, status);
                        break;
                }
        }

        return 0;
}
