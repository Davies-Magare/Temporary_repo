#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void sigHandler(int signum) {
    printf("Child process terminated by signal %d\n", signum);
    exit(EXIT_FAILURE);
}

int main(void)
{
    char str[] = "/bin/ls";
    char *args[] = {str, "-l", "/tmp", NULL};  // Command arguments
    pid_t pid;
    int status, i;

    pid_t childPids[5];  // Array to store child process IDs

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid > 0)
        {
            childPids[i] = pid;  // Store child process ID in the array
            waitpid(pid, &status, 0);
            if (!WIFEXITED(status))
            {
                if (WIFSIGNALED(status))
                {
                    printf("Process terminated by signal %i\n", WTERMSIG(status));
                    kill(pid, SIGTERM); // Send SIGTERM only to active child processes
                }
            }
        }
        else if (pid == 0)
        {
            signal(SIGTERM, sigHandler);
            execve(args[0], args, NULL); // Use the array of command arguments
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else
        {
            perror("fork:");
            exit(EXIT_FAILURE);
        }
    }

    return (0);
}

