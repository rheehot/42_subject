/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:16:18 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/11 09:41:49 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	check_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ans;
	unsigned char	*dst;
	int				tmp;

	ans = malloc(nmemb * size);
	if (ans == 0)
		return (0);
	tmp = nmemb * size;
	dst = ans;
	while (tmp > 0)
	{
		*dst = 0;
		dst++;
		tmp--;
	}
	return (ans);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (len == 0)
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

static int	ft_set_end(const char *s, char const *set)
{
	int	len;

	len = 0;
	while (s[len] != 0)
		len++;
	len--;
	while (len >= 0)
	{
		if (!check_set(s[len], set))
		{
			return (len);
		}
		len--;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = -1;
	while (s1[i] != 0)
	{
		if (!check_set(s1[i], set))
		{
			start = i;
			break ;
		}
		i++;
	}
	if (start == -1)
		return ((char *)ft_calloc(1, 1));
	end = ft_set_end(s1, set);
	return (ft_substr(s1, start, end - start + 1));
}
