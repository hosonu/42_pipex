/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/31 16:45:02 by hoyuki           ###   ########.fr       */
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
	pipex->file_two = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->file_two == -1)
	{
		perror(argv[4]);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	if (argc != 5)
	{
		errno = EINVAL;
		perror("argc");
		exit(EXIT_FAILURE);
	}
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (0);
	pipex->n = argc - 3;
	open_file(pipex, argv);
	if(pipe(pipex->pp) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	ft_pipex(pipex, argv, envp);
	free(pipex);
	return (0);
}

// int	main(int argc, char *argv[], char *envp[])
// {
// 	t_pipex	*pipex;

// 	if (argc != 5)
// 	{
// 		errno = EINVAL;
// 		perror("argc");
// 		exit(EXIT_FAILURE);
// 	}
// 	pipex = (t_pipex *)malloc(sizeof(t_pipex));
// 	if (pipex == NULL)
// 		return (0);
// 	pipex->n = argc - 3;
// 	open_file(pipex, argv);
// 	if(pipe(pipex->pp) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// 	pipex->pid1 = fork();
// 	if (pipex->pid1 == 0)
// 		comand_one(pipex, argv, envp);
// 	pipex->pid2 = fork();
// 	if (pipex->pid2 == 0)
// 		comand_two(pipex, argv, envp);
// 	close(pipex->pp[0]);
// 	close(pipex->pp[1]);
// 	waitpid(pipex->pid1, NULL, 0);
// 	waitpid(pipex->pid2, NULL, 0);
// 	free(pipex);
// 	return (0);
// }