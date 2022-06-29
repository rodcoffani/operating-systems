#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// function that will be executed by the thread
void *func(void *arg) {
	void *pointer = NULL;

	printf("Thread created...\n");

	sleep(10);
	pthread_exit(0);

	return pointer;
}

int main() {
	pthread_t thread;
	int result;
	
	// creates thread
	// result = 0 -> success
	result = pthread_create(&thread, NULL, func(NULL), NULL);

	if(result != 0) {
		printf("Error! %d\n", result);
	}

	return 0;
}

