/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:01:16 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/18 17:28:22 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define COMAND_NOT_FOUND -1

typedef struct s_pipex
{
	int		pp[2];
	int		pid;
	int		infile;
	int		outfile;
	int		pcnt;
	bool	here_doc;
	char	*in_comand;
	char	**comand;
}			t_pipex;

// main.c functions prototypes
void		open_file(t_pipex *pipex, char *argv[], int argc);
int			main(int argc, char *argv[], char *envp[]);

// comands.c functions prototypes
char		*do_join(char *path, char *comand);
char		*path_lookup(char *envp[], t_pipex *pipex);
void		exec_cmd(t_pipex *pipex, char *argv[], char *envp[], int cnt);
void		child_process(t_pipex *pipex, int i, char *cmds[], char *envp[]);
void		run_process(t_pipex *pipex, char *cmds[], char *envp[]);

// error.c functions prototypes
void	error_print(char *message, int ernum, bool use_errno);

#endif
