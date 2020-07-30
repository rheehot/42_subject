/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:19:38 by seongpar          #+#    #+#             */
/*   Updated: 2020/07/16 21:19:41 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cal_size(long long nbr, char *base)
{
	int		size;
	int		base_size;

	size = 0;
	base_size = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		size += 1;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base_size;
		size++;
	}
	return (size);
}

static char	*ft_convert(char *result, long long nbr, char *base, int base_size)
{
	int		i;
	int		is_minus;

	i = 0;
	is_minus = 0;
	result = (char *)malloc(sizeof(char) * (cal_size(nbr, base) + 1));
	if (result)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			is_minus = 1;
		}
		else if (nbr == 0)
			result[i++] = '0';
		while (nbr > 0)
		{
			result[i++] = base[nbr % base_size];
			nbr /= base_size;
		}
		if (is_minus == 1)
			result[i++] = '-';
		result[i] = 0;
	}
	return (result);
}

static char	*ft_reverse(char *str)
{
	char	temp;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(str);
	while (i < size / 2)
	{
		temp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = temp;
		i++;
	}
	return (str);
}

char		*ft_lltoa_base(long long nbr, char *base)
{
	char	*result;

	result = 0;
	result = ft_convert(result, nbr, base, ft_strlen(base));
	if (result)
		result = ft_reverse(result);
	return (result);
}
