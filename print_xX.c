/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:53:58 by seongpar          #+#    #+#             */
/*   Updated: 2020/07/30 16:53:59 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check1(t_list *node, unsigned int num, char **print)
{
	if (node->length == 0 && num == 0 && node->precision == '.')
		*print = make_zero();
	else
		*print = ft_itox((long long)num, 'A');
	if (node->length < 0)
	{
		node->length = 0;
		node->precision = 0;
	}
}

static void	check2(t_list *node, unsigned int num, t_send2 s)
{
	char	*p;

	check1(node, num, &p);
	*s.printc = ft_max(ft_strlen(p), node->length);
	if (num < 0)
		*s.printw = ft_max(*s.printc + 1, node->width);
	else
		*s.printw = ft_max(*s.printc, node->width);
	if (node->flag == '0' && node->precision != '.')
	{
		if (num < 0)
			*s.printc = *s.printw - 1;
		else
			*s.printc = *s.printw;
	}
	*s.strc = (char *)malloc(*s.printc);
	*s.strw = (char *)malloc(*s.printw + 1);
	if (node->flag == '0' || node->length > 0)
		set_zero(*s.strc, *s.printc);
	else
		ft_setspace(*s.strc, *s.printc + 1);
	ft_setspace(*s.strw, *s.printw + 1);
	(*s.strw)[*s.printw] = 0;
	ft_memmove(&((*s.strc)[*s.printc - ft_strlen(p)]), p, ft_strlen(p));
	free(p);
}

static void	check3(t_list node, t_send2 s)
{
	if (node.flag == '-')
		ft_memmove(&((*s.strw)[0]), *s.strc, *s.printc);
	else
		ft_memmove(&((*s.strw)[*s.printw - *s.printc]), *s.strc, *s.printc);
	free(*s.strc);
	ft_putstr_fd(*s.strw, 1);
	free(*s.strw);
}

int			print_xx(t_list node, unsigned int num)
{
	t_send2	send;
	size_t	print_container;
	size_t	print_width;
	char	*str_container;
	char	*str_width;

	send.printc = &print_container;
	send.printw = &print_width;
	send.strc = &str_container;
	send.strw = &str_width;
	check2(&node, num, send);
	check3(node, send);
	return (print_width);
}
