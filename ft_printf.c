/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:56:22 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/20 19:09:47 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void	print_node(t_list point, va_list *ap)
{

	if (point.width == -1)
		point.width = va_arg(*ap, int);
	if (point.length == -1)
		point.length = va_arg(*ap, int);

	if (point.specifier != 's')
	{
		if (point.width < 0 && point.width != -2)
		{
			point.width *= -1;
			point.flag = '-';
		}
		if (point.length < 0 && point.length != -2)
		{
			point.length *= -1;
			point.flag = '-';
		}
	}
	else
	{
		if (point.width < 0 && point.width != -2)
		{
			point.width *= -1;
			point.flag = '-';
		}
		if (point.length < 0 && point.length != -2)
			point.length = -2;
	}

	if (point.specifier == 'd' || point.specifier == 'i')
		print_d(point, va_arg(*ap, int));
	else if (point.specifier == 'u')
		print_u(point, va_arg(*ap, unsigned int));
	else if (point.specifier == 'c')
		print_c(point, (char)va_arg(*ap, int));
	else if (point.specifier == 's')
		print_s(point, va_arg(*ap, char*));
	else if (point.specifier == 'x')
		print_x(point, va_arg(*ap, unsigned int));
	else if (point.specifier == 'X')
		print_X(point, va_arg(*ap, unsigned int));
	else if (point.specifier == '%')
		print_c(point, '%');
	else if (point.specifier == 'p')
	{
		write(1, "0x", 2);
		print_x(point, va_arg(*ap, unsigned int));
	}
}

void	write_string(t_list *point, const char * str, va_list *ap)
{
	int	i;
	int	state;

	state = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (state == 0 && str[i] == '%')
		{
			state = 1;
			print_node(*point, ap);
			point = point->next;
		}
		else if (state == 0)
			ft_putchar_fd(str[i], 1);
		else if (state && is_specifier(str[i]))
			state = 0;
		i++;
	}
}

int	ft_printf(const char * format, ... )
{
	t_list		*print_node;
	va_list		ap;

	va_start(ap, format);

	print_node = 0;
	ft_parse(format, &print_node);

	write_string(print_node, format, &ap);

	va_end(ap);
	return (ft_strlen(format));
}
