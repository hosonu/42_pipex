/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:04:34 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/27 15:26:00 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void rec(int n, int fd)
{
    char c;

    if(n > 0)
        n = -n;
    if(n <= -10)
        rec(n / 10, fd);
    c = -(n % 10) + '0';
    ft_putchar_fd(c, fd);
}

void ft_putnbr_fd(int n, int fd)
{
    if(n == 0)
        ft_putchar_fd('0', fd);
    if(n < 0)
        ft_putchar_fd('-', fd);
    if(n != 0)
        rec(n, fd);
}
