/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:13:16 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/25 12:57:42 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{	
		free(temp[i]);
		i++;
	}
	free(temp);
}

t_listnb	*init_list(char **av, t_data *data)
{
	char		**temp;
	int			i;
	t_listnb	*list;

	i = 1;
	list = NULL;
	while (av[i])
	{
		temp = ft_split(av[i], ' ');
		if (!temp[0])
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		list = new_list(list, temp);
		i++;
		free_temp(temp);
	}
	data->tab = sort_int_tab(init_tab(list), ft_lstsize(list), data);
	data->tab_len = ft_lstsize(list);
	return (list);
}

t_listnb	*new_list(t_listnb *list, char **temp)
{
	int	nb;
	int	j;

	if (!temp[0])
		return (NULL);
	j = 0;
	while (temp[j])
	{
		nb = ft_atoi(temp[j]);
		if (nb > __INT_MAX__ || nb < -2147483648)
		{
			free_temp(temp);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		ft_lstadd_back(&list, ft_lstnew(nb));
		j++;
	}
	return (list);
}

int	check_tri(t_listnb *lst)
{
	t_listnb	*temp;

	temp = lst;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_doublon(t_listnb *lst)
{
	t_listnb	*temp;

	temp = lst->next;
	while (lst)
	{
		while (temp)
		{
			if (temp->content == lst->content)
				return (1);
			temp = temp->next;
		}
		lst = lst->next;
		if (lst)
			temp = lst->next;
	}
	return (0);
}
