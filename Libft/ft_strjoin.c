/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:43:31 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/12 10:03:53 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init(size_t *len1, size_t *len2, char const *s1, char const *s2)
{
	*len1 = ft_strlen(s1);
	*len2 = ft_strlen(s2);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	i;
	size_t	len1;
	size_t	len2;

	init(&len1, &len2, s1, s2);
	ans = (char *)malloc(len1 + len2 + 1);
	if (ans == 0)
		return (0);
	i = 0;
	while (i < len1)
	{
		ans[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		ans[i] = s2[i - len1];
		i++;
	}
	ans[i] = 0;
	return (ans);
}
