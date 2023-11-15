/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/15 17:26:24 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *argv[], t_pipex *pipex)
{
	char	*line;

	pipex->infile = open("tmpfile", O_RDWR | O_CREAT, 0644);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			pipex->here_doc = 1;
			free(line);
			break ;
		}
		write(pipex->infile, line, ft_strlen(line));
		free(line);
	}
}

void	open_file(t_pipex *pipex, char *argv[], int argc)
{
	if (pipex->here_doc == 1)
		pipex->infile = open("tmpfile", O_RDONLY);
	else
		pipex->infile = open(argv[2], O_RDONLY);
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
	t_pipex	pipex;

	if (argc < 5)
	{
		errno = EINVAL;
		perror("argc");
		exit(EXIT_FAILURE);
	}
	pipex.here_doc = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc(argv, &pipex);
	open_file(&pipex, argv, argc);
	pipex.pcnt = argc - 3 - pipex.here_doc;
	run_process(&pipex, argv, envp);
	if (pipex.here_doc == 1)
		unlink("tmpfile");
	return (0);
}

//error handling
//output "comand not found"
//output "permission denied"
//output "no such file or directory"