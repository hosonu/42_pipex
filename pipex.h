/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:01:16 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/03 20:48:58 by hoyuki           ###   ########.fr       */
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
	int		pid1;
	int		pid2;
	int		file_one;
	int		file_two;
	int 	pcnt;
	char	*input;
	char	*in_comand;
	char	**comand;
}			t_pipex;

char		*get_path(char *envp[], t_pipex *pipex);
void		comand_one(t_pipex *pipex, char *argv[], char *envp[]);
void		comand_two(t_pipex *pipex, char *argv[], char *envp[]);
void ft_pipex(t_pipex *pipex, char *argv[], char *envp[]);
void exec_cmd(t_pipex *pipex, char *argv[], char *envp[], int cnt);


#endif
