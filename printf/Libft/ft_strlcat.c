/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:32:54 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/12 10:04:12 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	int		i;
	size_t	n;
	int		dlen;

	d = dst;
	i = 0;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (src[i] != '\0')
	{
		if (n != 1)
		{
			*d++ = src[i];
			n--;
		}
		i++;
	}
	*d = '\0';
	return (dlen + i);
}
