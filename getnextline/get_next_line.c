/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 16:14:29 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/29 19:26:44 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int get_next_line(int fd, char **line)
{
	static char	*left_str[MAX_SIZE];
	char		buf[BUFFER_SIZE + 1];
	char		*new;
	int			len;
	int			idx;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_SIZE)
		return (ERROR);

	while ((idx = find_endl(left_str[fd])) == -1)
	{
		if (read(fd, buf, BUFFER_SIZE) < 0)
			return (ERROR);
		left_str[fd] = ft_strjoin(left_str[fd], buf);
	}
	
	len = ft_strlen(left_str[fd]);
	left_str[fd][idx] = 0;
	line = ft_strdup(left_str[fd]);

	new = (char *)malloc(sizeof(char) * len - idx);
	ft_memmove(new, &left_str[fd][idx + 1], len - idx);
	free(left_str[fd]);
	return 1;
}
