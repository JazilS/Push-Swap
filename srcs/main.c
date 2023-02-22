/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:13:07 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/22 21:41:06 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_data		*data;
	t_listnb	*lst;
	t_listnb	*b;

	(void)ac;
	data = malloc(sizeof(t_data));
	lst = init_list(av);
	b = NULL;
	if (check_doublon(lst))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (check_tri(lst))
		return (ft_putstr_fd("Error\n", 2), 0);
	data->tab = sort_int_tab(init_tab(lst), ft_lstsize(lst), data);
	data->tab_len = ft_lstsize(lst);
	if (ft_lstsize(lst) == 3)
		tri3(&lst, data);
	else if (ft_lstsize(lst) == 5)
		tri5(&lst, data, &b);
	else
		tri(&lst, &b, data);
	return (0);
}
