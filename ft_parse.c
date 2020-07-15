/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:56:12 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/20 17:25:00 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	pass_num(const char *str, size_t *idx, t_list *node, int isW)
{
	int ans;

	ans = 0;
	if (str[*idx] == '*')
	{
		*idx = *idx + 1;
		if (isW)
			node->b_width = 1;
		else
			node->b_length = 1;
	}
	while (str[*idx] != 0)
	{
		if ('0' > str[*idx] || str[*idx] > '9')
			break ;
		ans = ans * 10 + str[*idx] - '0';
		*idx = *idx + 1;
	}
	if (isW)
		node->width = ans;
	else
		node->length = ans;
}

void	make_node(t_list **start, t_list set_node)
{
	t_list *tmp;

	tmp = ft_lstnew(set_node);
	ft_lstadd_back(start, tmp);
}

void	ft_parse(const char *str, t_list **start)
{
	size_t	i;
	int		state;
	t_list	set_node;

	i = 0;
	state = 0;
	while (str[i] != 0)
	{
		if (state == 0 && str[i] == '%')
		{
			state = 1;
		}
		else if (state && str[i - 1] == '%' && is_flag(str[i]))
			set_node.flag = str[i];
		else if (state && is_width(str[i]) && set_node.precision == 0)
		{
			pass_num(str, &i, &set_node, 1);
			continue ;
		}
		else if (state && is_precision(str[i]))
			set_node.precision = str[i];
		else if (state && is_length(str[i]) && set_node.precision != 0)
		{
			pass_num(str, &i, &set_node, 0);
			continue ;
		}
		else if (state && is_specifier(str[i]))
		{
			set_node.specifier = str[i];
			make_node(start, set_node);
			state = 0;
		}
		i++;
	}
}
