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
	node->b_width = set_node.b_width;
	node->b_length = set_node.b_length;
	node->next = 0;
	return (node);
}