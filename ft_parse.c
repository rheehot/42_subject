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

void	pass_num(const char *str, size_t *idx, t_list *node, int is_width)
{
	int ans;

	ans = 0;
	if (str[*idx] == '*')
	{
		*idx = *idx + 1;
		if (is_width)
			node->s_width = 1;
		else
			node->s_length = 1;
		return ;
	}
	while (str[*idx] != 0)
	{
		if ('0' > str[*idx] || str[*idx] > '9')
			break ;
		ans = ans * 10 + str[*idx] - '0';
		*idx = *idx + 1;
	}
	if (is_width)
		node->width = ans;
	else
		node->length = ans;
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

void	ft_parse(const char *str, t_list **start)
{
	size_t	i;
	int		state;
	int		flag;
	t_list	set_node;

	i = 0;
	state = 0;
	flag = 0;
	while (str[i] != 0)
	{
		if (state == 0 && str[i] == '%')
		{
			state = 1;
			parse_init_node(&set_node);
			i++;
			flag = 1;
			continue ;
		}
		
		if (is_flag(str[i]) == 0)
			flag = 0;

		if (state && is_flag(str[i]) && flag)
		{
			if (set_node.flag == 0)
				set_node.flag = str[i];
			else if (str[i] == '-')
				set_node.flag = str[i];
		}
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
