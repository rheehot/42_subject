/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:51:54 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/27 15:40:11 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (len == 0 || ft_strlen(s) <= start)
		return ((char *)ft_calloc(1, 1));
	sub = (char *)ft_calloc(len + 1, 1);
	if (sub == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (s[start + i] == 0)
			break ;
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
