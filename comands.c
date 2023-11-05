/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:22:10 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/05 19:20:28 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_lookup(char *envp[], t_pipex *pipex)
{
	int		i;
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
				if (access(path[i], X_OK) == 0)
					return (path[i]);
				free(path[i]);
				i++;
			}
		}
		i++;
	}
	return (NULL);
}

void	exec_cmd(t_pipex *pipex, char *argv[], char *envp[], int cnt)
{
	char	*path;

	pipex->in_comand = argv[cnt + 2];
	if (access(pipex->in_comand, X_OK) == 0 && argv[cnt + 2][0] == '.')
		execve(pipex->in_comand, &pipex->in_comand, envp);
	path = path_lookup(envp, pipex);
	if (path == NULL)
	{
		perror("path");
		exit(0);
	}
	execve(path, pipex->comand, envp);
}
//fix fd line 
void	child_process(t_pipex *pipex, int i, char *cmds[], char *envp[])
{
	if (i == 0)
	{
		close(pipex->pp[0][0]);
		dup2(pipex->pp[0][1], STDOUT_FILENO);
		dup2(pipex->infile, STDIN_FILENO);
	}
	else if (i == pipex->pcnt - 1)
	{
		close(pipex->pp[i][1]);
		dup2(pipex->pp[i][0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->pp[i - 1][0], STDIN_FILENO);
		dup2(pipex->pp[i][1], STDOUT_FILENO);
	}
	exec_cmd(pipex, cmds, envp, i);
}

void	run_process(t_pipex *pipex, char *cmds[], char *envp[])
{
	int	i;

	i = 0;
	while (i < pipex->pcnt)
	{
		if (i < pipex->pcnt - 1)
		{
			if (pipe(pipex->pp[i]) == -1)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
		}
		pipex->pid = fork();
		if (pipex->pid == 0)
			child_process(pipex, i, cmds, envp);
		else if (pipex->pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

//TO DO : add func for parents process close several time



void	ft_pipex(t_pipex *pipex, char **cmds, char *envp[])
{
	run_process(pipex, cmds, envp);
	close(pipex->pp[0]);
	close(pipex->pp[1]);
	waitpid(pipex->pid, NULL, 0);
}
