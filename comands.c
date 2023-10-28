/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:22:10 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/28 11:39:50 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    comand_one(t_pipex *pipex, char *argv[], char *envp[])
{
    char	*path;

    // dup2(pipex->pp[1], 1);
    close(pipex->pp[0]);
    pipex->in_comand = argv[1];
    path = get_path(envp, pipex);
    if (path == NULL)
    {
        printf("Error\n");
        exit(0);
    }
    execve(path, pipex->comand, envp);
}

void    comand_two(t_pipex *pipex, char *argv[], char *envp[])
{
    char	*path;

    close(pipex->pp[1]);
    // dup2(pipex->pp[0], 0);
    close(pipex->pp[0]);
    pipex->in_comand = argv[2];
    path = get_path(envp, pipex);
    if (path == NULL)
    {
        printf("Error\n");
        exit(0);
    }
    execve(path, pipex->comand, envp);
}
