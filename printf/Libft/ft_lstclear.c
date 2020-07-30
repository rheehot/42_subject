/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:34:13 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/02 18:41:48 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*point;
	t_list	*tmp;

	point = *lst;
	while (point != 0)
	{
		tmp = point->next;
		free(point);
		point = tmp;
	}
	*lst = 0;
}
