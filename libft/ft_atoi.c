/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:00:28 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/27 11:45:07 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "libft.h"

char	*too_long(char *str, long long int *num)
{
	while (*str >= '0' && *str <= '9')
	{
		*num = (*num * 10) + (*str - '0');
		str++;
	}
	return (str);
}

long long int	ft_atoi(const char *nptr, char **temp)
{
	long long int	num;
	int				sign;
	char			*str;

	str = (char *)nptr;
	sign = 1;
	num = 0;
	if (*str + 1 == '-' || *str + 1 == '+')
		return (0);
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	str = too_long(str, &num);
	if (*str)
	{
		free_temp(temp);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (num * sign);
}
