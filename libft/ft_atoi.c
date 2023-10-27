/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hoyuki <hoyuki@student.42tokyo.jp>         +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/09/20 15:56:12 by hoyuki            #+#    #+#             */
/*   Updated: 2023/09/20 15:56:12 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_validate_long(const char *str, long long sign)
{
	long long nb;

	nb = 0;
	while (*str && (ft_isdigit(*str)))
	{
		if ((nb * sign) > (LONG_MAX - (*str - '0')) / 10)
			return (LONG_MAX);
		if ((nb * sign) < (LONG_MIN + (*str - '0')) / 10)
			return (LONG_MIN);
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}

int	ft_atoi(const char *str)
{
	long long sign;

	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (int)(ft_validate_long(str, sign));
}
