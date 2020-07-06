/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:41:05 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/02 15:06:11 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*search;
	unsigned int	i;

	search = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (search[i] == (unsigned char)c)
			return ((void *)&search[i]);
		i++;
	}
	return (0);
}
