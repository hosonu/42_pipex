/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/18 17:59:15 by hoyuki           ###   ########.fr       */
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
		if (line == NULL)
		{
			close(pipex->infile);
			free(line);
			error_print("get_next_line", 0, 0);
		}
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
			&& ft_strlen(line) - 1 == ft_strlen(argv[2]))
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
	else if (pipex->here_doc == 0)
		pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		error_print(argv[1], 0, 0);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile == -1)
		error_print(argv[argc - 1], 0, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		i;

	i = 0;
	if (argc < 5)
		error_print("argc", EINVAL, 1);
	pipex.here_doc = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
		here_doc(argv, &pipex);
	open_file(&pipex, argv, argc);
	pipex.pcnt = argc - 3 - pipex.here_doc;
	run_process(&pipex, argv, envp);
	if (pipex.here_doc == 1)
		unlink("tmpfile");
	while (i < pipex.pcnt)
	{
		wait(NULL);
		i++;
	}
	return (0);
}
