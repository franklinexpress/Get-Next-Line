/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:51:53 by fde-los-          #+#    #+#             */
/*   Updated: 2016/10/07 06:39:06 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_new_map;
	t_list	*new_map;

	new_map = NULL;
	tmp_new_map = NULL;
	if ((new_map = (t_list *)malloc(sizeof(t_list))))
	{
		new_map = f(ft_lstnew(lst->content, lst->content_size));
		tmp_new_map = new_map;
		lst = lst->next;
		while (lst)
		{
			tmp_new_map->next = f(ft_lstnew(lst->content, lst->content_size));
			tmp_new_map = tmp_new_map->next;
			lst = lst->next;
		}
	}
	return (new_map);
}
