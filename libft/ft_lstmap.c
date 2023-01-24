/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:32:12 by jsabound          #+#    #+#             */
/*   Updated: 2023/01/23 16:02:14 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_listnb	*ft_lstmap(t_listnb *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_listnb	*res;
// 	t_listnb	*temp;

// 	temp = ft_lstnew(f(lst->content));
// 	if (!temp)
// 	{
// 		ft_lstclear(&lst, del);
// 		return (NULL);
// 	}
// 	res = temp;
// 	lst = lst->next;
// 	while (lst)
// 	{
// 		temp = ft_lstnew(f(lst->content));
// 		if (!temp)
// 		{
// 			ft_lstclear(&lst, del);
// 			ft_lstclear(&res, del);
// 			break ;
// 		}
// 		lst = lst->next;
// 		ft_lstadd_back(&res, temp);
// 	}
// 	return (res);
// }
