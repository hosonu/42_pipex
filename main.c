/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/26 19:17:03 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    char *program;
    char *path = get_path(envp);
    t_line *input;
    input = malloc(sizeof(t_list));
    if(input == NULL)
        return 0;
    get_comand(argv[2] , input);
    char *args[] = {path, input->option1, NULL};
    if(argc <= 1)
    {
        printf("ouput error\n");
        return 0;
    }
    program = ft_strjoin(path, input->comand1);
    if (execve(program, args, NULL) == -1) {
        perror("execve"); 
    }
    return 0;
}
