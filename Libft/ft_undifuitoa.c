/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undifitoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:55:10 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/10 10:24:35 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*init(unsigned int *n, int *len)
{
	char			*tmp;
	unsigned int	num;

	*len = 0;
	num = *n;
	while (num > 0)
	{
		*len += 1;
		num /= 10;
	}
	tmp = malloc(*len + 1);
	return (tmp);
}

static char	*is_zero(void)
{
	char *tmp;

	tmp = malloc(2);
	tmp[0] = '0';
	tmp[1] = 0;
	return (tmp);
}

char		*ft_undifuitoa(unsigned int n)
{
	char	*ans;
	int		len;

	if (n == 0)
		return (is_zero());
	ans = (char *)init(&n, &len);
	ans[len--] = 0;
	while (n > 0)
	{
		ans[len--] = n % 10 + '0';
		n /= 10;
	}
	return (ans);
}
