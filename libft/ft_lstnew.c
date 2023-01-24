/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:58:54 by jsabound          #+#    #+#             */
/*   Updated: 2023/01/23 15:54:31 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listnb	*ft_lstnew(int content)
{
	t_listnb	*new;

	new = malloc(sizeof(t_listnb));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
