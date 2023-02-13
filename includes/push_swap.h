/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:05:36 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/13 17:13:01 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_data
{
	int		nb_max;
	int		mediane;
	int		*tab;
	int		check;
}			t_data;

t_listnb	*init_list(char **av);
t_listnb	*convert(long int *tab, t_data *data);
int			check_tri(t_listnb *lst);
int			check_doublon(t_listnb *lst);
void		swap(t_listnb **lst);
void		rotate(t_listnb **a);
void		rrotate(t_listnb **a);
void		push_a(t_listnb **a, t_listnb **b);
void		push_b(t_listnb **a, t_listnb **b);
void		rrr(t_listnb **a, t_listnb **b);
void		rr(t_listnb **a, t_listnb **b);
int	*init_tab(t_listnb *lst);
int	*sort_int_tab(int *tab, unsigned int size, t_data *data);
void		pre_tri(t_listnb **a, t_listnb **b, t_data *data);
void		aff(t_listnb *temp);
void	tri3(t_listnb **a, t_data *data);
int put_val_top(t_listnb **a, int val);
void tri5(t_listnb **a, t_data *data, t_listnb **b);


#endif