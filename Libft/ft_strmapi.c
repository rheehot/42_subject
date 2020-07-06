/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:32:53 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/13 10:02:38 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	char		*ans;
	size_t		i;

	len = ft_strlen(s);
	ans = (char *)malloc(len * sizeof(char) + 1);
	if (ans == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		ans[i] = f(i, s[i]);
		i++;
	}
	ans[i] = 0;
	return (ans);
}
