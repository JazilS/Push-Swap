/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:39:02 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/22 21:03:06 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tri3(t_listnb **a, t_data *data)
{
	while (!check_tri(*a))
	{
		if ((*a)->content == data->tab[2]
			&& (*a)->next->content == data->tab[0])
			rotate_a(a);
		else if ((*a)->content == data->tab[2]
			&& (*a)->next->content == data->tab[1])
		{
			rotate_a(a);
			swap(a);
		}
		tri3_suite(a, data);
	}
}

void	tri3_suite(t_listnb **a, t_data *data)
{
	if ((*a)->content == data->tab[1] && (*a)->next->content == data->tab[2])
	{
		rotate_a(a);
		rotate_a(a);
	}
	else if (((*a)->content == data->tab[1]
			&& (*a)->next->content == data->tab[0]))
		swap(a);
	else if (((*a)->content == data->tab[0]
			&& (*a)->next->content == data->tab[2]))
	{
		swap(a);
		rotate_a(a);
	}
}

int	put_val_top_a(t_listnb **a, int val)
{
	int	size;
	int	pos;

	if (!*a || ft_lstsize(*a) < 2 || (*a)->content == val)
		return (0);
	size = ft_lstsize(*a);
	pos = get_pos(*a, val);
	while ((*a)->content != val)
	{
		if (pos > (size / 2))
			rrotate_a(a);
		else
			rotate_a(a);
	}
	return (1);
}

int	put_val_top_b(t_listnb **b, int val)
{
	int	size;
	int	pos;

	if (!*b || ft_lstsize(*b) < 2 || (*b)->content == val)
		return (0);
	size = ft_lstsize(*b);
	pos = get_pos(*b, val);
	while ((*b)->content != val)
	{
		if (pos > (size / 2))
			rrotate_b(b);
		else
			rotate_b(b);
	}
	return (1);
}
