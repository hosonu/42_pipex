/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:22:10 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/17 00:57:20 by hosonu           ###   ########.fr       */
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

	pipex->in_comand = argv[cnt + 2 + pipex->here_doc];
	if ((argv[cnt + 2][0] == '.' || argv[cnt + 2][0] == '/'))
	{
		if (access(pipex->in_comand, X_OK) == 0)
		{
			execve(pipex->in_comand, &pipex->in_comand, envp);
			error_print("access", errno, 0);
		}
		else
			error_print("zsh", errno, 0);
	}
	path = path_lookup(envp, pipex);
	if (path == NULL)
		error_print(NULL, EXIT_FAILURE, 1);
	execve(path, pipex->comand, envp);
	error_print("execve", errno, 0);
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
			error_print("pipe", errno, 0);
		pipex->pid = fork();
		if (pipex->pid < 0)
			error_print("fork", errno, 0);
		else if (pipex->pid == 0)
			child_process(pipex, i, cmds, envp);
		dup2(pipex->pp[0], STDIN_FILENO);
		close(pipex->pp[1]);
		close(pipex->pp[0]);
		i++;
	}
}
