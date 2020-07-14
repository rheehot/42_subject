/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 23:01:54 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/20 19:10:07 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	print_d(t_list node, int num)
{
	char	*print;
	size_t	print_container;
	size_t	print_width;
	char	*str_container;
	char	*str_width;

	init_node(&node);
	print = ft_undifitoa(num);
	print_container = ft_max(ft_strlen(print), node.length);
	if (num < 0)
		print_width = ft_max(print_container + 1, node.width);
	else
		print_width = ft_max(print_container, node.width);
	str_container = (char *)malloc(print_container);
	str_width = (char *)malloc(print_width + 1);
	if (node.flag == '0' || node.length > 0)
		ft_bzero(str_container, print_container);
	else
		ft_setspace(str_container, print_container + 1);
	ft_setspace(str_width, print_width + 1);
	str_width[print_width] = 0;
	ft_memmove(&str_container[print_container - ft_strlen(print)], print, ft_strlen(print));
	free(print);
	if (node.flag == '-' && num < 0)
	{
		ft_memmove(&str_width[1], str_container, print_container);
		str_width[0] = '-';
	}
	else if (node.flag == '-')
		ft_memmove(&str_width[0], str_container, print_container);
	else if (num < 0)
	{
		ft_memmove(&str_width[print_width - print_container], str_container, print_container);
		str_width[print_width - print_container - 1] = '-';
	}
	else
		ft_memmove(&str_width[print_width - print_container], str_container, print_container);
	free(str_container);
	ft_putstr_fd(str_width, 1);
	free(str_width);

	return (print_width);
}


int	print_u(t_list node, unsigned int num)
{
	char	*print;
	size_t	print_container;
	size_t	print_width;
	char	*str_container;
	char	*str_width;

	init_node(&node);
	print = ft_undifitoa((long long)num);
	print_container = ft_max(ft_strlen(print), node.length);
	print_width = ft_max(print_container, node.width);

	str_container = (char *)malloc(print_container);
	str_width = (char *)malloc(print_width + 1);

	if (node.flag == '0' || node.length > 0)
		ft_bzero(str_container, print_container);
	else
		ft_setspace(str_container, print_container + 1);
	ft_setspace(str_width, print_width + 1);
	str_width[print_width] = 0;

	ft_memmove(&str_container[print_container - ft_strlen(print)], print, ft_strlen(print));
	free(print);
	if (node.flag == '-')
		ft_memmove(&str_width[0], str_container, print_container);
	else
		ft_memmove(&str_width[print_width - print_container], str_container, print_container);
	free(str_container);

	ft_putstr_fd(str_width, 1);
	free(str_width);

	return (print_width);
}
