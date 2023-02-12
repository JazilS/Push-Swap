/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:28 by jsabound          #+#    #+#             */
/*   Updated: 2023/01/25 14:07:20 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long int	num;
	char		*str;

	str = (char *)nptr;
	sign = 1;
	num = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n') || (*str == '\v')
		|| (*str == '\f') || (*str == '\r'))
		str++;
	if (*str + 1 == '-' || *str + 1 == '+')
		return (0);
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if ((num * sign) > __INT_MAX__ || (num * sign) < -2147483648)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		str++;
	}
	if (*str)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (num * sign);
}
