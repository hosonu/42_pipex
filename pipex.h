/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:01:16 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/04 01:16:43 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sysexits.h>
# include <errno.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		pp[2];
	int		pid;
	int		infile;
	int		outfile;
	int 	pcnt;
	char	*in_comand;
	char	**comand;
}			t_pipex;

//main.c functions prototypes
void	open_file(t_pipex *pipex, char *argv[], int argc);
int		main(int argc, char *argv[], char *envp[]);

//comands.c functions prototypes
char	*path_lookup(char *envp[], t_pipex *pipex);
void	exec_cmd(t_pipex *pipex, char *argv[], char *envp[], int cnt);
void	child_process(t_pipex *pipex, int i, char *cmds[], char *envp[]);
void	run_process(t_pipex *pipex, char *cmds[], char *envp[]);
void	ft_pipex(t_pipex *pipex, char *cmds[], char *envp[]);

#endif
