/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:13:16 by jsabound          #+#    #+#             */
/*   Updated: 2023/01/24 14:50:00 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


long int *init_string(char **av, t_data *data)
{
	char **temp;
	long int *tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(tab));
	temp = ft_split(av[1], ' ');
	i = 0;
	while(temp[i])
	{
		tab[i] = ft_atoi(temp[i]);
		i++;
	}
	data->tab_len = i;
	return (tab);
}


long int *init_arg(char **av, int ac, t_data *data)
{
	long int *tab;
	int i;
	int j;

	tab = malloc(sizeof(tab) * ac);
	if (!tab)
		return (NULL);
	i = 1;
	j = 0;
	while(av[i])
	{
		tab[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	data->tab_len = i;
	return (tab);
}

t_listnb *convert(long int *tab, t_data *data)
{
	t_listnb *temp;
	int		i;
	
	temp = ft_lstnew(tab[0]);
	if (!temp)
		return (NULL);
	i = 1; 
	while(i < data->tab_len)
		ft_lstadd_back(&temp, ft_lstnew(tab[i++]));
	return (temp);
}