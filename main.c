/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/26 12:32:58 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    char *program;
    char *path = get_path(envp);
    char *args[] = {path, argv[2], NULL};

    if(argc <= 1)
    {
        printf("ouput error\n");
        return 0;
    }
    program = ft_strjoin(path, argv[1]);
    if (execve(program, args, NULL) == -1) {
        perror("execve"); 
    }
    return 0;
}
