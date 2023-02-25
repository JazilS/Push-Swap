/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:39:57 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/25 11:38:42 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*init_tab(t_listnb *lst)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * ft_lstsize(lst));
	if (!tab)
		return (0);
	i = 0;
	while (lst)
	{
		tab[i] = lst->content;
		i++;
		lst = lst->next;
	}
	return (tab);
}

int	*sort_int_tab(int *tab, unsigned int size, t_data *data)
{
	int				tmp;
	unsigned int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	data->nb_max = tab[i];
	data->mediane = tab[i / 2];
	data->min = tab[0];
	return (tab);
}

void	pre_tri(t_listnb **a, t_listnb **b, t_data *data)
{
	while ((*a)->next)
	{
		if ((*a)->content == data->nb_max)
			rotate_a(a);
		else
		{
			push_b(a, b);
			if ((*b)->content < data->mediane)
				rotate_b(b);
		}
	}
}

int	get_pos(t_listnb *lst, int val)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		if (lst->content == val)
			return (i);
		i++;
		lst = lst->next;
	}
	return (0);
}

void	reset_rot(t_listnb **a, t_data *data)
{
	int	pos;

	pos = get_pos(*a, data->min);
	while ((*a)->content != data->min)
	{
		if (pos > (data->tab_len / 2) - 1)
			rrotate_a(a);
		else
			rotate_a(a);
	}
}
