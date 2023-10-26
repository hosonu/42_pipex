/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:28 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/26 12:28:39 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_path(char *envp[])
{
    int i = 0;
    char **path;
    char *path_to_bin;

    while(envp[i] != NULL)
    {
        if(ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            path = ft_split(envp[i], ':');
            path_to_bin = ft_strjoin(path[5], "/");
            return path_to_bin;
        }
        i++;
    }
    return NULL;
}
