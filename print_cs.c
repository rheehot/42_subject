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

int	print_c(t_list node, char c)
{
	size_t	print_container;
	size_t	print_width;
	char	*str_container;
	char	*str_width;
	
	if (node.length < 0)
		node.length = 0;
	print_container = ft_max(1, node.length);
	print_width = ft_max(print_container, node.width);

	str_container = (char *)malloc(print_container);
	str_width = (char *)malloc(print_width + 1);

	if (node.flag == '0' || node.length > 0)
		set_zero(str_container, print_container);
	else
		ft_setspace(str_container, print_container + 1);
	ft_setspace(str_width, print_width + 1);
	str_width[print_width] = 0;

	if (c == 0)
		str_container[0] = 0;
	else
		str_container[0] = c;

	ft_memmove(&str_container[print_container - 1], &c, 1);
	if (node.flag == '-')
		ft_memmove(&str_width[0], str_container, print_container);
	else
		ft_memmove(&str_width[print_width - print_container], str_container, print_container);
	free(str_container);

	if(c == 0)
		ft_putzero_fd(str_width, 1);
	else
		ft_putstr_fd(str_width, 1);
	free(str_width);

	return (print_width);
}

void	set_length_str(size_t *container, size_t *width, t_list node, char *print)
{
	int len_c;

	// printf("node.length : %d ", node.length);
	if (node.length == 0 && node.precision == '.')
	{
		print = make_zero();
		*container = 0;
		*width = ft_max(*container, node.width);
		// printf("!");
		return ;
	}

	if (node.length < 0)
	{
		node.length = 0;
		node.precision = 0;
		node.length = (int)ft_strlen(print);
		// printf("?");
	}
	
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

	// printf("node.width %d node.length %d ", node.width, node.length);
	// printf("print_container %zu print_width %zu ", print_container, print_width);

	str_container = (char *)malloc(print_container);
	str_width = (char *)malloc(print_width + 1);

	if (node.flag == '0' || node.length > 0)
		set_zero(str_container, print_container);
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

	return (print_width);
}
