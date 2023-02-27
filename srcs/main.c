/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:13:07 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/27 12:00:51 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clear_list(t_listnb *lst)
{
	t_listnb	*temp;

	temp = lst;
	if (lst)
	{
		while (lst)
		{
			temp = lst->next;
			free(lst);
			lst = temp;
		}
	}
}

void	free_all(t_listnb *a, t_listnb *b, t_data *data)
{
	if (a)
		clear_list(a);
	if (b)
		clear_list(b);
	if (data && data->tab)
		free(data->tab);
	if (data)
		free(data);
}

void	trii(t_listnb **lst, t_listnb **b, t_data **data)
{
	if (ft_lstsize(*lst) == 3)
		tri3(lst, *data);
	else if (ft_lstsize(*lst) == 2)
		swap(lst);
	else if (ft_lstsize(*lst) == 5)
		tri5(lst, *data, b);
	else
		tri(lst, b, *data);
}

int	main(int ac, char **av)
{
	t_data		*data;
	t_listnb	*lst;
	t_listnb	*b;

	(void)ac;
	if (ac > 1)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		lst = init_list(av, data);
		b = NULL;
		if (check_doublon(lst))
			return (free_all(lst, b, data), ft_putstr_fd("Error\n", 2), 0);
		if (check_tri(lst))
			return (free_all(lst, b, data), 0);
		trii(&lst, &b, &data);
		return (free_all(lst, b, data), 0);
	}
	return (0);
}
