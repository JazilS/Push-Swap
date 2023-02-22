/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:51:10 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/22 21:03:38 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_listnb **a, t_listnb **b)
{
	rotate_a(a);
	rotate_b(b);
}

void	rrotate_a(t_listnb **a)
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
	ft_putstr_fd("rra\n", 1);
}

void	rrotate_b(t_listnb **a)
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
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_listnb **a, t_listnb **b)
{
	rrotate_a(a);
	rrotate_b(b);
}
