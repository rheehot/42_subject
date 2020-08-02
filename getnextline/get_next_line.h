/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 16:32:53 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/27 17:51:02 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100
# define MAX_SIZE 256
# define ERROR -1

int		get_next_line(int fd, char **line);
void	*ft_memchr(const void *s, int c, int n);
int		ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *src);

#endif
