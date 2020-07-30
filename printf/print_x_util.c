/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:43:07 by seongpar          #+#    #+#             */
/*   Updated: 2020/07/30 17:43:08 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*init(long long *n, int *len)
{
	char		*tmp;
	long long	num;

	if (*n < 0ll)
		*n *= -1;
	*len = 0;
	num = *n;
	while (num > 0ll)
	{
		*len += 1;
		num /= 16;
	}
	tmp = malloc(*len + 1);
	return (tmp);
}

static char		*is_zero(void)
{
	char	*tmp;

	tmp = malloc(2);
	tmp[0] = '0';
	tmp[1] = 0;
	return (tmp);
}

char			*ft_itox(long long n, char alpha)
{
	char	*ans;
	int		len;

	if (n == 0)
		return (is_zero());
	ans = (char *)init(&n, &len);
	ans[len--] = 0;
	while (n > 0)
	{
		if ((n % 16) < 10)
			ans[len--] = n % 16 + '0';
		else
			ans[len--] = n % 16 - 10 + alpha;
		n /= 16;
	}
	return (ans);
}
