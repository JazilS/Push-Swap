/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:13:16 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/22 21:41:21 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_listnb	*init_list(char **av)
{
	t_listnb	*list;
	char		**temp;
	int			i;
	int			j;
	int			nb;

	i = 1;
	list = NULL;
	while (av[i])
	{
		temp = ft_split(av[i], ' ');
		j = 0;
		if (!temp[0])
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		while (temp[j])
		{
			nb = ft_atoi(temp[j]);
			ft_lstadd_back(&list, ft_lstnew(nb));
			j++;
		}
		i++;
	}
	return (list);
}

int	check_tri(t_listnb *lst)
{
	t_listnb	*temp;

	temp = lst;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_doublon(t_listnb *lst)
{
	t_listnb	*temp;

	temp = lst->next;
	while (lst)
	{
		while (temp)
		{
			if (temp->content == lst->content)
				return (1);
			temp = temp->next;
		}
		lst = lst->next;
		if (lst)
			temp = lst->next;
	}
	return (0);
}
