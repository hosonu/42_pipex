/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:01:16 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/30 13:00:15 by hosonu           ###   ########.fr       */
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
	int		pid1;
	int		pid2;
	int		file_one;
	int		file_two;
	char	*input;
	char	*in_comand;
	char	**comand;
}			t_pipex;

char		*get_path(char *envp[], t_pipex *pipex);
void		comand_one(t_pipex *pipex, char *argv[], char *envp[]);
void		comand_two(t_pipex *pipex, char *argv[], char *envp[]);

#endif
