/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:05:36 by jsabound          #+#    #+#             */
/*   Updated: 2023/01/24 12:38:27 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_data
{
	int tab_len;
}		t_data;

long int *init_string(char **av, t_data *data);
long int	*init_arg(char **av, int ac, t_data *data);
t_listnb *convert(long int *tab, t_data *data);
int			check_tri(t_listnb *lst);
// int check_doublon(char **str);
int			check_nb(char **str);
int			check_doublon(t_listnb *lst);

#endif