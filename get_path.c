/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:28 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/27 20:48:28 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//PATHを取得する
char	*get_path(char *envp[], t_line *input)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			i = 0;
			while (path[i] != NULL)
			{
				path[i] = ft_strjoin(path[i], "/");
				path[i] = ft_strjoin(path[i], input->comand1);
				if(access(path[i], X_OK) == 0)
					return path[i];
				i++;
			}
		}
		i++;
	}
	return (NULL);
}

//comanndo を分割して、comand1とoption1に格納する
void get_comand(char *comand, t_line *input)
{
	char **comand_line;
    
	if(comand != NULL)
	{
		comand_line = ft_split(comand, ' ');
		input->comand1 = comand_line[0];
		input->option1 = comand_line[1];
	}
}
