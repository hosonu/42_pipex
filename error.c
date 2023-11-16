/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:58 by hosonu            #+#    #+#             */
/*   Updated: 2023/11/16 15:36:43 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_check(char *message, int ernum, bool status)
{
    if (status == 0)
    {
        perror(message);
        exit(ernum);
    }
    else 
    {
        write(2, "command not found", 17);
        exit(ernum);
    }
}