#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int sum(int num);

int main(int argc, char *argv[])
{
    pid_t pid;
    int result;
    printf("calculate: 1 + 2 + 3 + ... + 10\n");
    pid = fork();
    switch (pid)
    {
    case -1:
        perror("fork failed");
        break;
    case 0: // 子process
        result = sum(10);
        break;
    default:
        break;
    }

    if (pid != 0)
    {
        int stat_val;
        pid_t child_pid;
        child_pid = wait(&stat_val);
        if (WIFEXITED(stat_val))
            printf("Result: %d\n", WEXITSTATUS(stat_val));
        else
            printf("Child terminated abnormally\n");
    }

    exit(result);
    return EXIT_SUCCESS;
}

int sum(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++)
        sum += i;
    return sum;
}