/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:28 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/27 16:54:55 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//PATHを取得する
char	*get_path(char *envp[])
{
	int		i;
	char	**path;
	char	*path_to_bin;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i], ':');
			i = 0;
			while (path[i] != NULL)
			{
				if (ft_strncmp(path[i], "/bin", 4) == 0)
					path_to_bin = ft_strjoin(path[i], "/");
				i++;
			}
			return (path_to_bin);
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
