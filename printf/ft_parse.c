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

void		pass_num(const char *str, size_t *idx, t_list *node, int is_width)
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

static void	check(t_send1 s, t_list *n, t_list **start)
{
	if (*(s.state) && is_flag((s.str)[*(s.i)]) && s.flag)
	{
		if (n->flag == 0)
			n->flag = (s.str)[*(s.i)];
		else if ((s.str)[*(s.i)] == '-')
			n->flag = (s.str)[*(s.i)];
	}
	else if (*(s.state) && is_width((s.str)[*(s.i)]) && n->precision == 0)
	{
		pass_num((s.str), s.i, n, 1);
		*(s.i) -= 1;
	}
	else if (*(s.state) && is_precision((s.str)[*(s.i)]))
		n->precision = (s.str)[*(s.i)];
	else if (*(s.state) && is_length((s.str)[*(s.i)]) && n->precision != 0)
	{
		pass_num((s.str), s.i, n, 0);
		*(s.i) -= 1;
	}
	else if (*(s.state) && is_specifier((s.str)[*(s.i)]))
	{
		n->specifier = (s.str)[*(s.i)];
		make_node(start, *n);
		*(s.state) = 0;
	}
}

static void	check2(t_send1 s, t_list *n, int *flag)
{
	if (*(s.state) == 0 && (s.str)[*(s.i)] == '%')
	{
		*(s.state) = 1;
		parse_init_node(n);
		*(s.i) += 1;
		*flag = 1;
		return ;
	}
	if (is_flag((s.str)[*(s.i)]) == 0)
		*flag = 0;
}

void		ft_parse(const char *str, t_list **start)
{
	size_t	i;
	int		state;
	int		flag;
	t_list	set_node;
	t_send1	send;

	i = 0;
	state = 0;
	flag = 0;
	while (str[i] != 0)
	{
		send.state = &state;
		send.str = str;
		send.i = &i;
		send.flag = flag;
		check2(send, &set_node, &flag);
		send.state = &state;
		send.str = str;
		send.i = &i;
		send.flag = flag;
		check(send, &set_node, start);
		i++;
	}
}
