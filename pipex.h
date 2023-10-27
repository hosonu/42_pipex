/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:01:16 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/27 20:28:38 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct p_line
{
	char	*comand1;
	char	*option1;
}			t_line;

char		*get_path(char *envp[], t_line *input);
void		 get_comand(char *comand, t_line *input);

#endif
