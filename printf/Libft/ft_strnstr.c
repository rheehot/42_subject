/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:55:02 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/26 18:19:06 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	j = 0;
	while (1)
	{
		if (little[j] == '\0')
			return ((char *)(big + (i - j)));
		if (big[i] == little[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		if (big[i] == '\0' || i >= len)
			return (NULL);
		i++;
	}
	return (0);
}
