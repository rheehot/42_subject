/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:14:17 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/12 10:36:39 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*new_node(void *content, void (*del)(void *))
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == 0)
	{
		del(content);
		return (0);
	}
	node->content = content;
	node->next = 0;
	return (node);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*tmp;

	ans = 0;
	while (lst != 0)
	{
		tmp = new_node(f(lst->content), del);
		ft_lstadd_back(&ans, tmp);
		lst = lst->next;
	}
	return (ans);
}
