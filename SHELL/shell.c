#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
#include <unistd.h> //fork
#include <sys/types.h> //fork, _exit
#include <wait.h> //wait
#include <stdlib.h> //exit, atoi
#include <string.h>

int main(int argc, char* argv[]){

	char s[1000]; //hello#world#of#linux
	char* t[100]; // 0 1 2 3

	t[0] = "/bin/bash";
	t[1] = "-c";
	t[3] = NULL;
	do {
		printf("$ Enter your command: ");
		fgets(s, 1000, stdin);
		char *pch = strtok(input, "\n");
		t[2] = input;
		if(strcmp(pch, "exit") == 0){
		break;
		}
		pid_t p = fork();
		if (p == 0){
			execvp(t[0], t);
		}
		waitpid(p, NULL,0);
	}
	while(1);
	return 0;
}
