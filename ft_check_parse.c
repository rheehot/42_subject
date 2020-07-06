/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:08:00 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/12 12:08:29 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

int	is_width(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else if (c == '*')
		return (1);
	return (0);
}

int	is_precision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	is_length(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else if (c == '*')
		return (1);
	return (0);
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' ||  c == 'p' || \
		c == 'd' || c == 'i' || c == 'u' || \
		c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
