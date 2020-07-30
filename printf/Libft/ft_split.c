/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:20:56 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/27 15:33:15 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	pass_char(char const **s, char c, int i, int mode)
{
	if (mode == 0)
	{
		while ((*s)[i] == c)
			i++;
	}
	else
	{
		while (i > 0)
		{
			i--;
			free((void *)s[i]);
		}
		free(s);
	}
	return (i);
}

static int	init(char const *s, char c)
{
	int	i;
	int	state;
	int	num;

	i = 0;
	state = 0;
	num = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && state == 0)
		{
			state = 1;
			num++;
		}
		if (s[i] == c && state == 1)
			state = 0;
		i++;
	}
	return (num);
}

static char	*copy_str(int i, int pos, char const *s)
{
	char	*tmp;
	int		j;

	tmp = malloc(i - pos + 1);
	if (tmp == 0)
		return (0);
	j = 0;
	while (pos != i)
	{
		tmp[j] = s[pos];
		j++;
		pos++;
	}
	tmp[j] = 0;
	return (tmp);
}

static int	ft_funct(char **ans, char c, char const *s, int *num)
{
	int	i;
	int	pos;

	i = pass_char(&s, c, 0, 0);
	pos = i;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			ans[(*num)++] = copy_str(i, pos, s);
			if (ans[(*num) - 1] == 0)
			{
				pass_char((char const **)ans, c, *num - 1, 1);
				return (0);
			}
			i = pass_char(&s, c, i, 0);
			pos = i;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		ans[(*num)++] = copy_str(i, pos, s);
	ans[(*num)] = 0;
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	**ans;
	int		size;
	int		num;

	num = 0;
	size = init(s, c);
	ans = malloc((size + 1) * sizeof(char *));
	if (ans == 0)
		return (0);
	if (size == 0)
	{
		ans[0] = 0;
		return (ans);
	}
	if (ft_funct(ans, c, s, &num) == 0)
		return (0);
	return (ans);
}
