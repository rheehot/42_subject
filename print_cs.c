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

void	init_node(t_list *node)
{
	if (node->width == -2)
		node->width = 0;
	if (node->length == -2)
		node->length = 0;
}

int	print_c(t_list node, char c)
{
	size_t	print_container;
	size_t	print_width;
	char	*str_container;
	char	*str_width;

	init_node(&node);
	print_container = ft_max(1, node.length);
	print_width = ft_max(print_container, node.width);

	str_container = (char *)malloc(print_container);
	str_width = (char *)malloc(print_width + 1);

	if (node.flag == '0' || node.length > 0)
		ft_bzero(str_container, print_container);
	else
		ft_setspace(str_container, print_container + 1);
	ft_setspace(str_width, print_width + 1);
	str_width[print_width] = 0;
	str_container[0] = c;

	ft_memmove(&str_container[print_container - 1], &c, 1);
	if (node.flag == '-')
		ft_memmove(&str_width[0], str_container, print_container);
	else
		ft_memmove(&str_width[print_width - print_container], str_container, print_container);
	free(str_container);

	ft_putstr_fd(str_width, 1);
	free(str_width);

	return (0);
}

void	set_length_str(size_t *container, size_t *width, t_list node, char *print)
{
	int len_c;

	if (node.length == -2)
		node.length = (int)ft_strlen(print);
	if (node.width == -2)
		node.width = 0;

	if (node.length > (int)ft_strlen(print))
	{
		len_c = ft_strlen(print);
	}
	else
	{
		len_c = node.length;
		len_c = ft_max(0, node.length);
	}
	*container = len_c;
	*width = ft_max(*container, node.width);
}

int	print_s(t_list node, char *print)
{
	size_t	print_container;
	size_t	print_width;
	char	*str_container;
	char	*str_width;

	set_length_str(&print_container, &print_width, node, print);

	str_container = (char *)malloc(print_container);
	str_width = (char *)malloc(print_width + 1);

	if (node.flag == '0' || node.length > 0)
		ft_bzero(str_container, print_container);
	else
		ft_setspace(str_container, print_container + 1);
	ft_setspace(str_width, print_width + 1);
	str_width[print_width] = 0;

	ft_memmove(&str_container[0], print, print_container);
	if (node.flag == '-')
		ft_memmove(&str_width[0], str_container, print_container);
	else
		ft_memmove(&str_width[print_width - print_container], str_container, print_container);
	free(str_container);

	ft_putstr_fd(str_width, 1);
	free(str_width);

	return (0);
}
