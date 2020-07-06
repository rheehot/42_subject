/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 12:13:46 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/13 10:00:10 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	void		*ans;

	len = ft_strlen(s);
	ans = malloc(len + 1);
	if (ans == 0)
		return (0);
	((char *)ans)[len] = 0;
	ans = ft_memcpy(ans, (void *)s, len + 1);
	return (ans);
}
