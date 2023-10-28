/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:28 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/28 11:53:03 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void get_comand(t_pipex *pipex)
{
	char **comand_line;

	comand_line = ft_split(pipex->in_comand, ' ');
	pipex->comand[0] = comand_line[0];
	pipex->comand[1] = comand_line[1];
}

char	*get_path(char *envp[], t_pipex *pipex)
{
	int	i;
	char	**path;
	
	get_comand(pipex);

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
				path[i] = ft_strjoin(path[i], pipex->comand[0]);
				if(access(path[i], X_OK) == 0)
					return path[i];
				free(path[i]);
				i++;
			}
		}
		i++;
	}
	return (NULL);
}
