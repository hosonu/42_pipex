/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/30 13:03:33 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(t_pipex *pipex, char *argv[])
{
	pipex->file_one = open(argv[1], O_RDONLY);
	if (pipex->file_one == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	pipex->file_two = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
	if (pipe(pipex->pp) == -1)
	{
		perror("file");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (0);
	if (argc != 5)
	{
		errno = EINVAL;
		perror("argc");
		exit(EXIT_FAILURE);

	}
	open_file(pipex, argv);
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		comand_one(pipex, argv, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		comand_two(pipex, argv, envp);
	close(pipex->pp[0]);
	close(pipex->pp[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free(pipex);
	return (0);
}
