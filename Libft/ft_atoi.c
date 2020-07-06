/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:59:10 by seongpar          #+#    #+#             */
/*   Updated: 2020/04/10 10:18:45 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_whitespace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

static int	pass_space(const char *nptr)
{
	int i;

	i = 0;
	while (nptr[i] != 0 && is_whitespace(nptr[i]))
		i++;
	if (nptr[i] == 0)
		return (-1);
	return (i);
}

static int	init(int *ans, int *i, int *is_min, const char *nptr)
{
	*ans = 0;
	*is_min = 0;
	*i = pass_space(nptr);
	if (*i == -1)
		return (1);
	if (nptr[*i] == '-')
	{
		*is_min = 1;
		*i = *i + 1;
	}
	else if (nptr[*i] == '+')
		*i = *i + 1;
	return (0);
}

int			ft_atoi(const char *nptr)
{
	int ans;
	int i;
	int is_min;

	if (init(&ans, &i, &is_min, nptr))
		return (0);
	while (nptr[i] != 0)
	{
		if (nptr[i] < '0' || '9' < nptr[i])
			break ;
		ans = ans * 10 + nptr[i] - '0';
		i++;
	}
	if (is_min)
		ans *= -1;
	return (ans);
}
