/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:58 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/18 17:26:11 by hoyuki           ###   ########.fr       */
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
