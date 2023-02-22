/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:38:52 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/22 21:04:13 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_listnb **lst)
{
	t_listnb	*temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = (*lst);
	(*lst) = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
	ft_putstr_fd("sa\n", 1);
}

void	push_b(t_listnb **a, t_listnb **b)
{
	t_listnb	*temp;

	if (!(*a))
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	temp->next = (*b);
	(*b) = temp;
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_listnb **a, t_listnb **b)
{
	t_listnb	*temp;

	if (!(*b))
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	temp->next = (*a);
	(*a) = temp;
	ft_putstr_fd("pa\n", 1);
}

void	rotate_a(t_listnb **a)
{
	t_listnb	*first;
	t_listnb	*last;

	last = (*a)->next;
	first = *a;
	first->next = NULL;
	ft_lstadd_back(&last, first);
	(*a) = last;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_listnb **a)
{
	t_listnb	*first;
	t_listnb	*last;

	last = (*a)->next;
	first = *a;
	first->next = NULL;
	ft_lstadd_back(&last, first);
	(*a) = last;
	ft_putstr_fd("rb\n", 1);
}
