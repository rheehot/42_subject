/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:00:49 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/13 09:28:40 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	set_zero(void *s, size_t n)
{
	ft_memset(s, '0', n);
}

char	*make_zero(void)
{
	char *tmp;

	tmp = malloc(1);
	tmp[0] = 0;
	return (tmp);
}
