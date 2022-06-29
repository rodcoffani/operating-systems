#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main() {
	pid_t result;
	int count = 0;
	struct timespec time_init, time_end;

	// gets time before loop
	if (clock_gettime(CLOCK_REALTIME, &time_init) < 0)
		printf("Erro em clock_gettime (tempo incial)\n"); // clock_gettime error

	while(1) {
		// creates a new process
		result = fork();

		// stop on fail
		if(result == -1) {
			int err = errno;
			printf("\nOcorreu um erro: error %d\n\n", err);
			break;
		}

		// success on creating a process
		if(result == 0) {
			// Child process created...
			printf("Processo filho criado...\n");
			sleep(10);
			exit(0);
		}

		else {
			// increments the number of total child processes created
			count++;
		}
	}
	
	// gets time after loop
	if (clock_gettime(CLOCK_REALTIME, &time_end) < 0)
		printf("Erro em clock_gettime (tempo final)\n"); // clock_gettime error


	// Were created %d processes
	printf("Foram criados %d processos\n", count);

	// The elapsed time were %lf seconds
	printf("O tempo decorrido foi %lf segundos\n", (time_end.tv_sec + time_end.tv_nsec/10e9) - (time_init.tv_sec + time_init.tv_nsec/10e9) );

	return 0;
}

