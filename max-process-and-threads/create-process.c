#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
	pid_t result;

	result = fork();

	if(result == -1) {
		// Error creating a process
		perror("Erro na criação de processo");

		// encerra a execução uma vez que houve um erro na criação de um novo processo
		// ends the execution once there was an error creating a new process
		exit(0);
	}

	if(result == 0) {
		// this is the child process, with pid %d, child of %d
		printf("Este é o processo filho, com pid %d, filho de %d\n", (int)getpid(), (int)getppid());
	} else {
		// this is process %d, parent of %d
		printf("Este é o processo %d, pai de %d\n", (int)getpid(), (int)result);
	}

	return 0;
}

