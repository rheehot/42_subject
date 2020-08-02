/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 16:32:43 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/27 19:48:44 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned int	i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while ((int)i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int		i;
	int		is_null;

	i = 0;
	is_null = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			is_null = 1;
		if (is_null == 0)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size1;
	int		size2;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	result[size1 + size2] = 0;
	if (result)
	{
		ft_strncpy(result, s1, size1);
		ft_strncpy(result + size1, s2, size2);
		free(s1);
		return (result);
	}
	free(s1);
	return (0);
}

char	*ft_strdup(char *src)
{
	int		size;
	int		i;
	char	*result;

	size = 0;
	i = 0;
	while (src[size])
		++size;
	result = (char *)malloc(size + 1);
	if (result != 0)
	{
		while (src[i])
		{
			result[i] = src[i];
			++i;
		}
		result[i] = 0;
	}
	return (result);
}
