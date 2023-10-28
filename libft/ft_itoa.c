/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:38:40 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/27 12:10:28 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	digits;

	digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	long long	nb;
	char		*str;
	int			digits;
	int			i;

	nb = n;
	digits = get_digits(n);
	str = (char *)malloc(sizeof(char) * digits + (n <= 0) + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	i = 0;
	while (nb > 0)
	{
		str[digits - (n > 0) - i++] = nb % 10 + '0';
		nb /= 10;
	}
	str[digits + (n <= 0)] = '\0';
	return (str);
}
