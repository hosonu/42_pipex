/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/28 11:22:14 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    t_pipex *pipex;

    pipex = (t_pipex *)malloc(sizeof(t_pipex));
    if (argc != 3)
    {
        printf("Error\n");
        return (0);
    }
    if(pipe(pipex->pp) == -1)
    {
        printf("Error\n");
        return (0);
    }
    pipex->pid1 = fork();
    if(pipex->pid1 == 0)
        comand_one(pipex, argv, envp);
    pipex->pid2 = fork();
    if(pipex->pid2 == 0)
        comand_two(pipex, argv, envp);
    close(pipex->pp[0]);
    close(pipex->pp[1]);
    waitpid(pipex->pid1, NULL, 0);
    waitpid(pipex->pid2, NULL, 0);
    return (0);
}
