#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int pp[2];

    pipe(pp);
    pid = fork();

    if(pid == 0)
    {
        close(pp[0]);//読み込み側を閉じる
        printf("child: %d\n", pid);
        write(pp[1], "hello", 5);
        close(pp[1]);
        exit(0);
    } else {
        close(pp[1]);//書き込み側を閉じる
        wait(NULL);
        printf("parent: %d\n", pid);
        close(pp[0]);
    }
    return 0;
}
