/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:22:10 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/28 17:55:46 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *envp[], t_pipex *pipex)
{
	int	i;
	char	**path;
	
	pipex->comand = ft_split(pipex->in_comand, ' ');
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			i = 0;
			while (path[i] != NULL)
			{
				path[i] = ft_strjoin(path[i], "/");
				path[i] = ft_strjoin(path[i], pipex->comand[0]);
				if(access(path[i], X_OK) == 0)
					return path[i];
				free(path[i]);
				i++;
			}
		}
		i++;
	}
	return (NULL);
}

void	comand_one(t_pipex *pipex, char *argv[], char *envp[])
{
	char	*path;

	close(pipex->pp[0]);
	dup2(pipex->pp[1], 1);
    dup2(pipex->file_one, 0);
	pipex->in_comand = argv[2];
	path = get_path(envp, pipex);
	if (path == NULL)
	{
        perror("path");
		exit(0);
	}
	execve(path, pipex->comand, envp);
}

void	comand_two(t_pipex *pipex, char *argv[], char *envp[])
{
	char	*path;

	close(pipex->pp[1]);
	dup2(pipex->pp[0], 0);
    dup2(pipex->file_two, 1);
	pipex->in_comand = argv[3];
	path = get_path(envp, pipex);
	if (path == NULL)
	{
		perror("path");
		exit(0);
	}
	execve(path, pipex->comand, envp);
}
