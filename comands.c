/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:22:10 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/03 21:03:07 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *envp[], t_pipex *pipex)
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

// void	comand_one(t_pipex *pipex, char *argv[], char *envp[])
// {
// 	char	*path;

// 	close(pipex->pp[0]);
// 	dup2(pipex->pp[1], 1);
// 	dup2(pipex->file_one, 0);
// 	pipex->in_comand = argv[2];
// 	//カレントディレクトリのファイルコマンドを実行
// 	if(ft_strncmp(pipex->in_comand, "./", 2) == 0)
// 		execve(pipex->in_comand, pipex->comand, envp);
// 	path = get_path(envp, pipex);
// 	if (path == NULL)
// 	{
// 		perror("path");
// 		exit(0);
// 	}
// 	execve(path, pipex->comand, envp);
// }

// void	comand_two(t_pipex *pipex, char *argv[], char *envp[])
// {
// 	char	*path;

// 	close(pipex->pp[1]);
// 	dup2(pipex->pp[0], 0);
// 	dup2(pipex->file_two, 1);
// 	pipex->in_comand = argv[3];
// 	if(ft_strncmp(pipex->in_comand, "./", 2) == 0)
// 		execve(pipex->in_comand, pipex->comand, envp);
// 	path = get_path(envp, pipex);
// 	if (path == NULL)
// 	{
// 		perror("path");
// 		exit(0);
// 	}
// 	execve(path, pipex->comand, envp);
// }


// void ft_pipex(t_pipex *pipex, char *argv[], char *envp[])
// {
// 	int cnt;
// 	cnt = 1;
// 	if(pipe(pipex->pp) == -1)
// 		exit(EXIT_FAILURE);
// 	pipex->pid = fork();
// 	if(pipex->pid == 0 && cnt == pipex->n)	
// 	{
// 		close(pipex->pp[1]);
// 		dup2(pipex->pp[0], 0);
// 		dup2(pipex->file_two, 1);
// 		exec_cmd(pipex, argv, envp, cnt);
// 	}
// 	while (pipex->pid == 0 && cnt++ < pipex->n)
// 	{
// 		close(pipex->pp[0]);
// 		dup2(pipex->pp[1], 1);
// 		dup2(pipex->file_one, 0);
// 		exec_cmd(pipex, argv, envp, cnt);
// 	}
// 	close(pipex->pp[0]);
// 	close(pipex->pp[1]);
// 	waitpid(pipex->pid, NULL, 0);
// }

void exec_cmd(t_pipex *pipex, char *argv[], char *envp[], int cnt)
{
	char	*path;

	pipex->in_comand = argv[cnt + 1];
	if(ft_strncmp(pipex->in_comand, "./", 2) == 0)
		execve(pipex->in_comand, pipex->comand, envp);
	path = get_path(envp, pipex);
	if (path == NULL)
	{
		perror("path");
		exit(0);
	}
	execve(path, pipex->comand, envp);	
}

void run_process(t_pipex *pipex, char *argv[], char *envp[])
{
	int i;
	i = 0;
	while(i < pipex->pcnt)
	{
		pipex->pid = fork();
		if(pipex->pid == 0)
		{
			if(i == 0)
			{
				close(pipex->pp[0]);
				dup2(pipex->pp[1], 1);
				dup2(pipex->file_two, 0);
			}
			else if(i == pipex->pcnt - 1)
			{
				close(pipex->pp[0]);
				dup2(pipex->pp[1], 1);
				dup2(pipex->file_one, 0);
				
			} else {
				dup2(pipex->pp[1], 1);
				dup2(pipex->file_two, 0);
			}
			exec_cmd(pipex, argv, envp, pipex->pcnt);
			exit(0);
		}
	}
}

void ft_pipex(t_pipex *pipex, char *argv[], char *envp[])
{
	int cnt;
	cnt = 1;
	if(pipe(pipex->pp) == -1)
		exit(EXIT_FAILURE);
	run_process(pipex, argv, envp);
	waitpid(pipex->pid, NULL, 0);
}