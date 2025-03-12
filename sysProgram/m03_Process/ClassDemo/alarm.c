#include<sys/types.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

static int alarm_fired = 0;

void ding(int sig) {
    alarm_fired = 1;
}

int main() {
    pid_t pid;
    int wait_sec = 2;
    printf("alarm application starting\n");
    pid = fork();

    switch (pid) {
        case -1: //fork失敗
            perror("fork failed");
            exit(1);
            break;
        case 0: //子處理
            sleep(wait_sec);
            kill(getppid(), SIGALRM);
            exit(0);
            break;
    }

    ///---只有父處理才能執行到這裡
    printf("wait %d sec for alarm to go off\n", wait_sec);
    (void)signal(SIGALRM, ding);
    pause();
    if (alarm_fired)
        printf("Ding!\n");
    printf("Done\n");
    exit(0);
}