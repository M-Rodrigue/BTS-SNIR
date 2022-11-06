#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void){
        int a = fork();
        if(a>0){
                printf("Je suis le père\n");
        } else {
                int b = fork();
                if(b>0){
                        printf("\tJe suis le fils\n");
                } else {
                        int c = fork();
                        if(c>0){
                                printf("\tJe suis le petit fils\n");
                        }  else {
                                printf("\t\tJe suis l'arrière petit fils");
                        }
                }
        }

        //printf("Je suis le processus de PID: %i et de PID parent: %i", int getpid(), int getppid());

        return 0;
}
