// Compile with `gcc foo.c -std=c99 -lpthread`, or use the makefile
// gcc -o foo foo.c
// ./foo

// We should use pthread_mutex_t because mutexes syncronize access to a resource. 
// It lockes so that only one thread can acquire the mutex at a time and change the variable.
// The mutex can only be unlocked by the thread that locked it, 
// and since we only have two treads with a single shared resource it will only lock 
// https://gustedt.wordpress.com/2010/06/29/semaphores/
// 

// I am solving with mutex lock since the time the variable is locked for is just one 
// addition or subtraction, which takes one clock tic. 
// If I were to solve this using semaphores, the amount of processing work in the 
// code would essentialy double. 

#include <pthread.h>
#include <stdio.h>

pthread_mutex_t count_mutex;
int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    for (int j = 0; j < 1000000; j++) {
	// TODO: sync access to i
        pthread_mutex_lock(&count_mutex);
	    i++;
        pthread_mutex_unlock(&count_mutex);
    }
    return NULL;
}

void* decrementingThreadFunction(){
    for (int j = 0; j < 1000000; j++) {
	// TODO: sync access to i
	    pthread_mutex_lock(&count_mutex);
	    i--;
        pthread_mutex_unlock(&count_mutex);
    }
    return NULL;
}


int main(){
    pthread_t incrementingThread, decrementingThread;
    
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
