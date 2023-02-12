/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:39:02 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/12 16:59:47 by jsabound         ###   ########.fr       */
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
	return (tab);
}

void	pre_tri(t_listnb **a, t_listnb **b, t_data *data)
{
	while ((*a))
	{
		if ((*a)->content == data->mediane)
		{
			rotate(a);
			(*a) = (*a)->next;
		}
		else
			push_b(a, b);
	}
}

int	get_pos(t_listnb *lst, int val)
{
	int i;

	if (!lst)
		return (0);
	i = 0;
	while(lst && lst->content != val)
	{
		if (lst->content == val)
			return (i);
		i++;
		lst = lst->next;
	}
	return (0);
}

void tri3(t_listnb **a, t_data *data)
{
	while (!check_tri(*a))
	{
		if ((*a)->content == data->tab[2] && (*a)->next->content == data->tab[0])
			rotate(a);	
		else if ((*a)->content == data->tab[2] && (*a)->next->content == data->tab[1])
		{
			rotate(a);
			swap(a);
		}		
		if ((*a)->content == data->tab[1] && (*a)->next->content == data->tab[2])
		{
			rotate(a);
			rotate(a);
		}
		else if (((*a)->content == data->tab[1] && (*a)->next->content == data->tab[0]))
			swap(a);
		else if (((*a)->content == data->tab[0] && (*a)->next->content == data->tab[2]))
		{
			swap(a);
			rotate(a);
		}
	}
}

int put_val_top(t_listnb **a, int val)
{
	int size;
	int pos;

	if (!*a || ft_lstsize(*a) < 2 || (*a)->content == val)
		return (0);
	size = ft_lstsize(*a);
	pos = get_pos(*a, val);
	while ((*a)->content != val)
	{
		if (pos > (size/ 2))
			rrotate(a);
		else
			rotate(a);
	}
	return (0);
}

void tri5(t_listnb **a, t_data *data, t_listnb **b)
{
	t_data temp;
	
	put_val_top(a, data->tab[0]);
	push_b(a, b);
	put_val_top(a, data->tab[1]);
	push_b(a, b);
	temp.tab = sort_int_tab(init_tab(*a), 3, &temp);
	tri3(a, &temp);
	push_b(b, a);
	push_b(b, a);
}