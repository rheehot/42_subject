/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:31:41 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/27 15:53:13 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_set(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)s;
	while (i < n)
	{
		dst[i] = c;
		i++;
	}
	return (s);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*ans;

	ans = malloc(nmemb * size);
	if (ans == 0)
		return (0);
	ft_set(ans, 0, nmemb * size);
	return ((void *)ans);
}
