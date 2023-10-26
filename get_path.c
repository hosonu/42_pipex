/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:28 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/26 17:46:14 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void get_comand(char *comand)
{
    t_list *input;
    
    input = malloc(sizeof(t_list));
    if(input == NULL)
        return ;
    input->comand1 = ft_split(comand , "");
}