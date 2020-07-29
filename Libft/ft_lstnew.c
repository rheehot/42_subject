/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:26:44 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/02 17:51:44 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(t_list set_node)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->flag = set_node.flag;
	node->width = set_node.width;
	node->precision = set_node.precision;
	node->length = set_node.length;
	node->specifier = set_node.specifier;
	node->s_width = set_node.s_width;
	node->s_length = set_node.s_length;
	node->next = 0;
	return (node);
}

void	parse_init_node(t_list *node)
{
	node->flag = 0;
	node->width = 0;
	node->precision = 0;
	node->length = 0;
	node->specifier = 0;
	node->next = 0;
	node->s_width = 0;
	node->s_length = 0;
}

void	make_node(t_list **start, t_list set_node)
{
	t_list *tmp;

	tmp = ft_lstnew(set_node);
	ft_lstadd_back(start, tmp);
}