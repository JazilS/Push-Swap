/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:04:04 by jsabound          #+#    #+#             */
/*   Updated: 2023/01/23 16:01:49 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstclear(t_listnb **lst, void (*del)(int))
// {
// 	t_listnb	*temp;

// 	temp = *lst;
// 	while (temp)
// 	{
// 		*lst = (*lst)->next;
// 		ft_lstdelone(temp, (*del));
// 		temp = *lst;
// 	}
// 	*lst = NULL;
// }
