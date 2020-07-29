/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 23:01:07 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/20 18:51:03 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check1(t_list *node, size_t *printc, size_t *printw)
{
	if (node->length < 0)
	{
		node->length = 0;
		node->precision = 0;
	}
	*printc = ft_max(1, node->length);
	*printw = ft_max(*printc, node->width);
	if (node->flag == '0' && node->precision != '.')
	{
		*printc = *printw;
	}
}

static void	check2(char *strc, char *strw, char c)
{
	free(strc);
	if (c == 0)
		ft_putzero_fd(strw, 1);
	else
		ft_putstr_fd(strw, 1);
	free(strw);
}

int			print_c(t_list node, char c)
{
	size_t	printc;
	size_t	printw;
	char	*strc;
	char	*strw;

	check1(&node, &printc, &printw);
	strc = (char *)malloc(printc);
	strw = (char *)malloc(printw + 1);
	if (node.flag == '0' || node.length > 0)
		set_zero(strc, printc);
	else
		ft_setspace(strc, printc + 1);
	ft_setspace(strw, printw + 1);
	strw[printw] = 0;
	if (c == 0)
		strc[0] = 0;
	else
		strc[0] = c;
	ft_memmove(&strc[printc - 1], &c, 1);
	if (node.flag == '-')
		ft_memmove(&strw[0], strc, printc);
	else
		ft_memmove(&strw[printw - printc], strc, printc);
	check2(strc, strw, c);
	return (printw);
}
