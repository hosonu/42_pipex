/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:58 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/20 16:38:06 by hoyuki           ###   ########.fr       */
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

bool	expand_envp(char *line, char *envp[], int infile)
{
	int	i;

	if (line[0] == '$')
	{
		i = 0;
		while (envp[i])
		{
			if (ft_strncmp(envp[i], line + 1, ft_strlen(line) - 2) == 0)
			{
				ft_putstr_fd(envp[i] + ft_strlen(line) - 1, infile);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
