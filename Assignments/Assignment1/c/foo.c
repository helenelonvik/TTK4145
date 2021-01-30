// Compile with `gcc foo.c -std=c99 -lpthread`, or use the makefile

#include <pthread.h>
#include <stdio.h>

int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    for (int j = 0; j < 1000000; j++){
        i++;
    }
    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    for (int j = 0; j< 1000000; j++){
        i--;
    }
    return NULL;
}


int main(){
    // TODO: declare incrementingThread and decrementingThread (hint: google pthread_create)
    pthread_t thread_1;
    pthread_t thread_2;
    pthread_create(&thread_1, NULL, incrementingThreadFunction, NULL);
    pthread_create(&thread_2, NULL, decrementingThreadFunction, NULL);
    
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
