/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:04:05 by seongpar          #+#    #+#             */
/*   Updated: 2020/07/29 14:04:06 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check1(t_list *node, char *print)
{
	if (node->length < 0)
	{
		node->length = 0;
		node->precision = 0;
		node->length = (int)ft_strlen(print);
	}
}

void		set_length_str(size_t *c, size_t *w, t_list node, char *print)
{
	int len_c;

	if (node.length == 0 && node.precision == '.')
	{
		print = make_zero();
		*c = 0;
		*w = ft_max(*c, node.width);
		return ;
	}
	check1(&node, print);
	if (node.s_length == 0 && node.length == 0)
		node.length = (int)ft_strlen(print);
	if (node.length > (int)ft_strlen(print))
	{
		len_c = ft_strlen(print);
	}
	else
	{
		len_c = node.length;
		len_c = ft_max(0, node.length);
	}
	*c = len_c;
	*w = ft_max(*c, node.width);
}

static void	set_malloc(char **sc, char **sw, size_t pc, size_t pw)
{
	*sc = (char *)malloc(pc);
	*sw = (char *)malloc(pw + 1);
}

int			print_s(t_list node, char *print)
{
	size_t	printc;
	size_t	printw;
	char	*strc;
	char	*strw;

	set_length_str(&printc, &printw, node, print);
	set_malloc(&strc, &strw, printc, printw);
	if (node.flag == '0' || node.length > 0)
		set_zero(strc, printc);
	else
		ft_setspace(strc, printc + 1);
	if (node.flag == '0')
		set_zero(strw, printw + 1);
	else
		ft_setspace(strw, printw + 1);
	strw[printw] = 0;
	ft_memmove(&strc[0], print, printc);
	if (node.flag == '-')
		ft_memmove(&strw[0], strc, printc);
	else
		ft_memmove(&strw[printw - printc], strc, printc);
	free(strc);
	ft_putstr_fd(strw, 1);
	free(strw);
	return (printw);
}
