/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:38:08 by jsabound          #+#    #+#             */
/*   Updated: 2023/01/25 17:20:20 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_listnb *lst)
{
	int			i;
	t_listnb	*temp;

	temp = lst;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
