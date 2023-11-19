/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:58 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/19 19:53:01 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_print(char *message, int ernum, bool use_errno)
{
	if (ernum >= 0)
	{
		if (use_errno == 1)
		{
			errno = ernum;
			perror(message);
			exit(EXIT_FAILURE);
		}
		perror(message);
		exit(EXIT_FAILURE);
	}
	else
	{
		write(2, "command not found\n", 18);
		exit(EXIT_FAILURE);
	}
}


bool expand_envp(char *line, char *envp[], int infile)
{
	if(line[0] == '$')
	{
		int i = 0;
		while(envp[i])
		{
			if(ft_strncmp(envp[i], line + 1, ft_strlen(line) - 2) == 0)
			{
				ft_putstr_fd(envp[i] + ft_strlen(line) - 1, infile);
				return 1;
			}
			i++;
		}
	}
	return 0;
}
