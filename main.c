/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/04 01:13:46 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(t_pipex *pipex, char *argv[], int argc)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile == -1)
	{
		perror(argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	if (argc < 5)
	{
		errno = EINVAL;
		perror("argc");
		exit(EXIT_FAILURE);
	}
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (0);
	pipex->pcnt = argc - 3;
	open_file(pipex, argv, argc);
	if(pipe(pipex->pp) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	ft_pipex(pipex, argv, envp);
	free(pipex);
	return (0);
}
