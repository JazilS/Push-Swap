/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:13:07 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/12 16:21:44 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void aff(t_listnb *temp)
{	
	while (temp)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
	}
}

int main (int ac, char **av)
{
	t_data *data;
	t_listnb *lst;
	t_listnb *b;
	
	(void)ac;
	
	data = malloc(sizeof(t_data));
	lst = init_list(av);
	// if (check_doublon(lst))
	// 	return (ft_putstr_fd("Error\n", 2), 0);
	// if (check_tri(lst))
	// 	return (ft_putstr_fd("Error\n", 2), 0);
	// reverse_rotate_a(&lst);
	// push_b(&lst, &b);
	data->tab = sort_int_tab(init_tab(lst), ft_lstsize(lst), data);
	// tri5(&lst, data, &b);
	
	pre_tri(&lst, &b, data);
	printf("-------A-------\n");
	aff(lst);
	printf("-------B-------\n");
	aff(b);

	return (0);
}