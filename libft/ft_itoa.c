/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:38:40 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/25 14:49:40 by hoyuki           ###   ########.fr       */
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
	int			digits;
	char		*str;
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

// #include <string.h>
// int main(void)
// {
//     char *p;
//     p = ft_itoa(-5859);
// 	printf("strlen: %lu\n",strlen(p));
//     printf("p: %s\n", p);
//     return (0);
// }
