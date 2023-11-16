/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:58 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/16 20:46:55 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_print(char *message, int ernum, bool status)
{
	if (status == 0)
	{
		perror(message);
		exit(ernum);
	}
	else
	{
		write(2, "zsh: command not found\n", 23);
		exit(ernum);
	}
}
