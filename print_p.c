/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 20:08:28 by seongpar          #+#    #+#             */
/*   Updated: 2020/07/16 20:08:32 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			print_p(t_list node, long long num)
{
	char	*print;
	size_t	print_container;
	size_t	print_width;
	char	*str_container;
	char	*str_width;

	if (node.length == 0 && num == 0 && node.precision == '.')
		print = make_zero();
	else
		print = ft_lltoa_base(num, "0123456789abcdef");
	
	if (node.length < 0)
	{
		node.length = 0;
		node.precision = 0;
	}

	print_container = ft_max(ft_strlen(print), node.length) + 2;
	if (num < 0)
		print_width = ft_max(print_container + 1, node.width);
	else
		print_width = ft_max(print_container, node.width);

	if (node.flag == '0' && node.precision != '.')
	{
		if (num < 0)
			print_container = print_width - 1;
		else
			print_container = print_width;
	}

	str_container = (char *)malloc(print_container);
	str_width = (char *)malloc(print_width + 1);


	if (node.flag == '0' || node.length > 0)
		set_zero(str_container, print_container);
	else
		ft_setspace(str_container, print_container + 1);
	
	str_container[0] = '0';
	str_container[1] = 'x';

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