/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:11:52 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/12 10:36:40 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*point;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	point = *lst;
	while (point != 0)
	{
		if (point->next == 0)
		{
			point->next = new;
			return ;
		}
		point = point->next;
	}
}
