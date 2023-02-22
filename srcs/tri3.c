/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:40:35 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/22 20:55:01 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tri5(t_listnb **a, t_data *data, t_listnb **b)
{
	t_data	temp;

	put_val_top_a(a, data->tab[0]);
	push_b(a, b);
	put_val_top_a(a, data->tab[1]);
	push_b(a, b);
	temp.tab = sort_int_tab(init_tab(*a), 3, &temp);
	tri3(a, &temp);
	push_a(b, a);
	push_a(b, a);
}

int	get_next_sup(t_listnb *a, int val, t_data *data)
{
	int			res;
	t_listnb	*temp;

	if (ft_lstsize(a) == 1)
		return (a->content);
	temp = a;
	res = data->nb_max;
	while (temp)
	{
		if (temp->content > val && temp->content <= res)
			res = temp->content;
		temp = temp->next;
	}
	return (res);
}

int	get_tmp(int tmp, int a, int b, int coup)
{
	if (tmp > (a / 2))
		tmp = a - tmp;
	if (coup > (b / 2))
		tmp += b - coup;
	else
		tmp += coup;
	return (tmp);
}

int	get_best(t_listnb *a, t_listnb *b, t_data *data)
{
	int	tmp;
	int	size_b;
	int	res;
	int	x;
	int	i;

	i = 1;
	size_b = ft_lstsize(b);
	res = get_pos(a, get_next_sup(a, b->content, data));
	res = get_tmp(res, ft_lstsize(a), size_b, i);
	x = b->content;
	while (b)
	{
		tmp = get_pos(a, get_next_sup(a, b->content, data));
		tmp = get_tmp(tmp, ft_lstsize(a), size_b, i);
		if (tmp < res)
		{
			res = tmp;
			x = b->content;
		}
		b = b->next;
		i++;
	}
	return (x);
}

void	tri(t_listnb **a, t_listnb **b, t_data *data)
{
	int	i;
	int	best;

	i = 0;
	pre_tri(a, b, data);
	while (i < data->tab_len - 1)
	{
		best = get_best(*a, *b, data);
		put_val_top_b(b, best);
		put_val_top_a(a, get_next_sup(*a, best, data));
		push_a(a, b);
		i++;
	}
	reset_rot(a, data);
}
