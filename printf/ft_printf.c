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

static void	check1(t_list *point)
{
	if (point->specifier != 's')
	{
		if (point->width < 0)
		{
			point->width *= -1;
			point->flag = '-';
		}
	}
	else
	{
		if (point->width < 0)
		{
			point->width *= -1;
			point->flag = '-';
		}
	}
}

static void	check2(t_list point, va_list *ap, int *result)
{
	char *tmp;

	if (point.specifier == 'd' || point.specifier == 'i')
		*result += print_d(point, va_arg(*ap, int));
	else if (point.specifier == 'u')
		*result += print_u(point, va_arg(*ap, unsigned int));
	else if (point.specifier == 'c')
		*result += print_c(point, (char)va_arg(*ap, int));
	else if (point.specifier == 's')
	{
		tmp = va_arg(*ap, char*);
		if (tmp == 0)
			*result += print_s(point, "(null)");
		else
			*result += print_s(point, tmp);
	}
	else if (point.specifier == 'x')
		*result += print_x(point, va_arg(*ap, unsigned int));
	else if (point.specifier == 'X')
		*result += print_xx(point, va_arg(*ap, unsigned int));
	else if (point.specifier == '%')
		*result += print_c(point, '%');
	else if (point.specifier == 'p')
		*result += print_p(point, (long long)va_arg(*ap, void *));
}

void		print_node(t_list point, va_list *ap, int *result)
{
	if (point.s_width == 1)
		point.width = va_arg(*ap, int);
	if (point.s_length == 1)
		point.length = va_arg(*ap, int);
	check1(&point);
	check2(point, ap, result);
}

void		write_string(t_list *p, const char *str, va_list *ap, int *r)
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
			print_node(*p, ap, r);
			p = p->next;
		}
		else if (state == 0)
		{
			ft_putchar_fd(str[i], 1);
			*r += 1;
		}
		else if (state && is_specifier(str[i]))
			state = 0;
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_list		*print_node;
	va_list		ap;
	int			result;

	result = 0;
	va_start(ap, format);
	print_node = 0;
	ft_parse(format, &print_node);
	write_string(print_node, format, &ap, &result);
	va_end(ap);
	ft_lstclear(&print_node);
	return (result);
}
