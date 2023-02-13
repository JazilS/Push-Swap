/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:51:10 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/13 17:53:27 by jsabound         ###   ########.fr       */
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
}

void	rotate(t_listnb **a)
{
	t_listnb	*first;
	t_listnb	*last;

	last = (*a)->next;
	first = *a;
	first->next = NULL;
	ft_lstadd_back(&last, first);
	(*a) = last;
}

void	rr(t_listnb **a, t_listnb **b)
{
	rotate(a);
	rotate(b);
}

void	rrotate(t_listnb **a)
{
	t_listnb	*last;
	t_listnb	*temp;
	t_listnb	*t;

	temp = (*a);
	last = ft_lstlast(temp);
	t = temp;
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
	last->next = t;
	(*a) = last;
}

void	rrr(t_listnb **a, t_listnb **b)
{
	rrotate(a);
	rrotate(b);
}