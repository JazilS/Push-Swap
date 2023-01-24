/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:08:42 by jsabound          #+#    #+#             */
/*   Updated: 2023/01/24 14:57:38 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
# include "../libft/libft.h"

// int check_nb(t_listnb *lst)
// {
// 	while(lst->next)
// 	{
		
// 	}
// }

int check_nb(char **str)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] < '0' && str[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// int check_doublon(long int *tab)
// {
// 	int i;
// 	int j;
	
// 	j = 0;
// 	i = 0;
// 	while(str[i])
// 	{
// 		j = 0;
// 		while(str[i][j])
// 		{
// 			if (str[i][j] == str[i][j + 1])
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int check_tri(t_listnb *lst)
{
	t_listnb *temp;

	temp = lst;
	while(temp->next)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

// int check_doublon(t_listnb *lst)
// {
// 	t_listnb *temp;

// 	temp = lst;
// 	while(temp->next)
// 	{
// 		while(lst->next)
// 		{
// 			printf("temp = %d\n", temp->content);
// 			printf("lst = %d\n", lst->next->content);
// 			if (temp->content == lst->next->content)
// 				return (1);
// 			lst = lst->next;
// 		}
// 		temp = temp->next;
// 		lst = temp->next;
// 	}
// 	return (0);
// }

int main (int ac, char **av)
{
	long int *str = 0;
	// t_listnb *list;
	t_data *data;

	data = malloc(sizeof(t_data));
	if (check_nb(av))
		return (printf("Error\nQue des nombres !\n"), 0);
	if (ac == 2)
		str = init_string(av, data);
	else if (ac > 2)
		str = init_arg(av, ac, data);
	
	int i = 0;
	while (str[i])
		printf("%ld\n", str[i++]);



	// list = convert(str, data);
	// if (check_doublon(list))
	// 	return (printf("doublon\n"), 0);
	// printf("qwe = %d\n", list->content);
	// while(list->next)
	// {
	// 	printf("%d\n", list->content);
	// 	list = list->next;
	// 	if (!list->next)
	// 		printf("%d\n", list->content);
	// }





	return (0);
}