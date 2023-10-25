#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        printf("ouput error\n");
        return 0;
    }
    char *program;
    program = ft_strjoin("/bin/", argv[1]);
    char *args[] = {"/bin/", argv[2], NULL};
    if (execve(program, args, NULL) == -1) {
        perror("execve"); 
    }
    return 0;
}
