#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int i,pid1,pid2,pid3,pid4,count;
	int status;
	if(argc!=3){
		printf("incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	int A,B,S;
pid1 = fork();
    if (pid1 == 0){   
        execlp("python3",":)","add.py",argv[1],argv[2],NULL);
        exit(EXIT_SUCCESS);
    }

    pid2 = fork();
    if (pid2 == 0){   
        execlp("java",":)","subtraction.java",argv[1],argv[2],NULL);
        exit(EXIT_SUCCESS);
    }
    
    pid3 = fork();
    if (pid3 == 0){   
        execlp("node",":)","multiplication.js",argv[1],argv[2],NULL);
        exit(EXIT_SUCCESS);
    }
    
    pid4 = fork();
    if (pid4 == 0){   
        execlp("bash",":)","division.sh",argv[1],argv[2],NULL);
        exit(EXIT_SUCCESS);
    }

    for (i = 0; i < 3; ++i){
        wait(&status);
    }

    printf("parent: done. \n");
    exit(EXIT_SUCCESS);
}
