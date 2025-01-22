/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:01:16 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/29 16:45:17 by hosonu           ###   ########.fr       */
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
# include <sys/wait.h>
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
	bool	is_invalid;
	char	*in_comand;
	char	**comand;
}			t_pipex;

// main.c functions prototypes
void		here_doc(char *argv[], t_pipex *pipex);
void		open_file(t_pipex *pipex, char *argv[], int argc);
int			main(int argc, char *argv[], char *envp[]);

// comands.c functions prototypes
char		*do_join(char *path, char *comand);
char		*path_lookup(char *envp[], t_pipex *pipex);
void		exec_cmd(t_pipex *pipex, char *argv[], char *envp[], int cnt);
void		child_process(t_pipex *pipex, int i, char *cmds[], char *envp[]);
void		run_process(t_pipex *pipex, char *cmds[], char *envp[]);

// pipex_utils.c functions prototypes
void		error_print(char *message, int ernum, bool use_errno);
// bool		expand_envp(char *line, char *envp[], int infile);

#endif
