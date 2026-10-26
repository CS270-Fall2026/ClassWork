#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid;

    if ((pid = fork()) == 0)
    {
        printf("Child is created\n");
        execlp("ls", "ls", NULL);
        printf("This will never executed\n");
    }
    else
    {
        printf("Child is playing...\n");
        int childStatus;
        int pidWait = wait(&childStatus);
        printf("child %d has terminated with status %d\n", pidWait, WEXITSTATUS(childStatus));
        printf("Parent is going home\n");
    }
    return 0;
}
