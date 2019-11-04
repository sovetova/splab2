#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    int i, pid,pid1,pid2,pid3,pid4,count;
    int status;
    if(argc!=3) {
        printf("incorrect number of arguments \n");
        exit(EXIT_FAILURE);
    }

    int A,B,S,rem;
    count=0;
    S=0;
    A=atoi(argv[1]);
    B=atoi(argv[2]);

    pid1 = fork();
    if (pid1 == 0)
    {   
        S=A+B;
        printf("child number 1: %d+%d=%d\n", A, B, S);
        exit(EXIT_SUCCESS);
    }

    pid2 = fork();
    if (pid2 == 0)
    {   
        pid=getpid();
        S=A-B;
        printf("child number 2: %d-%d=%d\n", A, B, S);
        exit(EXIT_SUCCESS);
    }
    
    pid3 = fork();
    if (pid3 == 0)
    {   
        pid=getpid();
        S=A*B;
        printf("child number 3: %d*%d=%d\n", A, B, S);
        exit(EXIT_SUCCESS);
    }
    
    pid4 = fork();
    if (pid4 == 0)
    {   
        pid=getpid();
        S=A/B;
        printf("child number 4: %d/%d=%d\n", A, B, S);
        exit(EXIT_SUCCESS);
    }

    for (i = 0; i < 3; ++i){
        wait(&status);
    }

    printf("parent: done. \n");
    exit(EXIT_SUCCESS);
}
