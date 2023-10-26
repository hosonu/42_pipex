/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/26 12:31:29 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    char *program;
    char *args[] = {get_path(envp), argv[2], NULL};
    
    if(argc <= 1)
    {
        printf("ouput error\n");
        return 0;
    }
    program = ft_strjoin(get_path(envp), argv[1]);
    if (execve(program, args, NULL) == -1) {
        perror("execve"); 
    }
    return 0;
}
