#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function(void *arg);

int main(int argc, char* argv[]) {
    int res;
    pthread_t a_thread;
    int sec = atoi(argv[1]);
    void *thread_result;
    res = pthread_create(&a_thread, NULL, thread_function, &sec);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined, it returnrd %s\n", (char*)thread_result);
    exit(EXIT_SUCCESS);
}

void* thread_function(void *arg) {
    int sec = *(int*)arg;
    printf("sleep(%d)", sec);
    fflush(stdout);
    for (int i = 0; i < sec; i++) {
        fflush(stdout);
        sleep(1);
        printf(".");
    }
    printf("\n");
    pthread_exit("Thanks for the CPU time");
}


