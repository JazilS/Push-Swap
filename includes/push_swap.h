/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:05:36 by jsabound          #+#    #+#             */
/*   Updated: 2023/02/25 11:41:17 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_data
{
	int		nb_max;
	int		mediane;
	int		tab_len;
	int		min;
	int		*tab;
}			t_data;

t_listnb	*init_list(char **av);
t_listnb	*convert(long int *tab, t_data *data);
int			check_tri(t_listnb *lst);
int			check_doublon(t_listnb *lst);
void		swap(t_listnb **lst);
void		rotate(t_listnb **a);
void		rrotate_a(t_listnb **a);
void		push_a(t_listnb **a, t_listnb **b);
void		push_b(t_listnb **a, t_listnb **b);
void		rrr(t_listnb **a, t_listnb **b);
void		rr(t_listnb **a, t_listnb **b);
int			*init_tab(t_listnb *lst);
int			*sort_int_tab(int *tab, unsigned int size, t_data *data);
void		pre_tri(t_listnb **a, t_listnb **b, t_data *data);
void		aff(t_listnb *temp);
void		tri3(t_listnb **a, t_data *data);
int			put_val_top_a(t_listnb **a, int val);
void		tri5(t_listnb **a, t_data *data, t_listnb **b);
void		rotate_a(t_listnb **a);
void		rotate_b(t_listnb **a);
void		tri(t_listnb **a, t_listnb **b, t_data *data);
int			get_best(t_listnb *a, t_listnb *b, t_data *data);
int			get_tmp(int tmp, int a, int b, int coup);
int			get_next_sup(t_listnb *a, int val, t_data *data);
int			get_pos(t_listnb *lst, int val);
int			put_val_top_b(t_listnb **b, int val);
void		rrotate_b(t_listnb **a);
void		reset_rot(t_listnb **a, t_data *data);
void		tri3_suite(t_listnb **a, t_data *data);
t_listnb	*new_list(t_listnb *list, char **temp);
void		free_all(t_listnb *a, t_listnb *b, t_data *data);

#endif