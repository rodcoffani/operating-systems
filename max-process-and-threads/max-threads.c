#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

// function that will be executed by the thread
void *func(void *arg) {
	// Thread created...
	printf("Thread %lu criada...\n", pthread_self());

	sleep(10);
	pthread_exit(NULL);

	return NULL;
}

int main() {
	pthread_t thread;
	int counter = 0;
	struct timespec time_init, time_end;
	int result = 0;
	int err;

	// gets time before loop
	if (clock_gettime(CLOCK_REALTIME, &time_init) < 0)
		printf("Erro em clock_gettime (tempo incial)\n"); // clock_gettime error

	// creates thread
	// result = 0 -> success
	while(result == 0) {
		result = pthread_create(&thread, NULL, &func, NULL);
		if (result != 0) {
			err = errno;
			printf("\nOcorreu um erro: error %d\n\n", err); // error number %d
		}
		else {
			counter++;
		}
	}

	// gets time after loop
	if (clock_gettime(CLOCK_REALTIME, &time_end) < 0)
		printf("Erro em clock_gettime (tempo final)\n"); // clock_gettime error

	// Were created %d threads
	printf("Foram criadas %d threads\n", counter);
	// The elapsed time were %lf seconds
	printf("O tempo decorrido foi %lf segundos\n", (time_end.tv_sec + time_end.tv_nsec/10e9) - (time_init.tv_sec + time_init.tv_nsec/10e9) );

	return 0;
}

