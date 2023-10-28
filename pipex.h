/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:01:16 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/28 11:52:36 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
#include "libft/libft.h"

typedef struct s_pipex
{
	int pp[2];
	int pid1;
	int pid2;
	char	*input;
	char 	*in_comand;
	char	*comand[2];
}			t_pipex;

char		*get_path(char *envp[], t_pipex *pipex);
void		 get_comand(t_pipex *pipex);
void    comand_one(t_pipex *pipex, char *argv[], char *envp[]);
void    comand_two(t_pipex *pipex, char *argv[], char *envp[]);


#endif
