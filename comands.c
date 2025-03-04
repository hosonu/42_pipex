/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:22:10 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/22 20:18:01 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*do_join(char *path, char *comand)
{
	path = ft_strjoin(path, "/");
	if (path == NULL)
		error_print("malloc", 0, 0);
	path = ft_strjoin(path, comand);
	if (path == NULL)
		error_print("malloc", 0, 0);
	return (path);
}

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
				path[i] = do_join(path[i], pipex->comand[0]);
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

	pipex->in_comand = argv[cnt + 2 + pipex->here_doc];
	if ((pipex->in_comand[0] == '.' || pipex->in_comand[0] == '/'))
	{
		pipex->comand = ft_split(pipex->in_comand, ' ');
		if (access(pipex->comand[0], X_OK) == 0)
		{
			execve(pipex->comand[0], pipex->comand, envp);
			error_print(pipex->in_comand, COMAND_NOT_FOUND, 0);
		}
		else
			error_print(pipex->in_comand, 0, 0);
	}
	path = path_lookup(envp, pipex);
	if (path == NULL)
		error_print(pipex->in_comand, COMAND_NOT_FOUND, 0);
	execve(path, pipex->comand, envp);
	error_print(pipex->in_comand, COMAND_NOT_FOUND, 0);
}

void	child_process(t_pipex *pipex, int i, char *cmds[], char *envp[])
{
	if (i == pipex->pcnt - 1)
	{
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->pp[0]);
		close(pipex->pp[1]);
		close(pipex->outfile);
	}
	else
	{
		dup2(pipex->pp[1], STDOUT_FILENO);
		close(pipex->pp[0]);
		close(pipex->pp[1]);
	}
	exec_cmd(pipex, cmds, envp, i);
}

void	run_process(t_pipex *pipex, char *cmds[], char *envp[])
{
	int	i;

	i = 0;
	dup2(pipex->infile, STDIN_FILENO);
	while (i < pipex->pcnt)
	{
		if (pipe(pipex->pp) == -1)
			error_print("pipe", 0, 0);
		pipex->pid = fork();
		if (pipex->pid < 0)
			error_print("fork", 0, 0);
		else if (pipex->pid == 0)
			child_process(pipex, i, cmds, envp);
		dup2(pipex->pp[0], STDIN_FILENO);
		close(pipex->pp[1]);
		close(pipex->pp[0]);
		i++;
	}
}
