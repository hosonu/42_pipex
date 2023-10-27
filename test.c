#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    
    pid = fork();
    // printf("%d\n", pid);
    int d = 0;
    d++;
    if(pid == 0)
    {
        d++;
        printf("%d\n", d);
        printf("child: %d\n", pid);
        exit(0);
    }
    printf("%d\n", d);
    printf("parent: %d\n", pid);
    return 0;
}
