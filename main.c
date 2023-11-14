/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/14 13:42:19 by hoyuki           ###   ########.fr       */
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

void here_doc(char *argv[])
{
	char	*line;
	
	line = NULL;
	while (get_next_line(0, line) > 0)
	{
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
			break ;
		free(line);
	}
	free(line);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc < 5)
	{
		errno = EINVAL;
		perror("argc");
		exit(EXIT_FAILURE);
	}
	pipex.pcnt = argc - 3;
	open_file(&pipex, argv, argc);
	// if(pipex.infile == 0)
	// 	here_doc(argv);
	ft_pipex(&pipex, argv, envp);
	return (0);
}
