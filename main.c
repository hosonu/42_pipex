/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:04:30 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/27 20:41:12 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    // char *program;
    t_line *input;
    input = malloc(sizeof(t_list));
    if(input == NULL)
        return 0;
    get_comand(argv[1] , input);
    char *path = get_path(envp, input);
    printf("%s\n", path);
    // char *args[] = {path, input->option1, NULL};
    // if(argc <= 1)
    // {
    //     printf("ouput error\n");
    //     return 0;
    // }
    // program = ft_strjoin(path, input->comand1);
    // if (execve(program, args, NULL) == -1) {
    //     perror("execve"); 
    // }
    return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}
