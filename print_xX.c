/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongpar <seongpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 23:01:50 by seongpar          #+#    #+#             */
/*   Updated: 2020/03/20 18:51:17 by seongpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*init(long long *n, int *len)
{
	char	    *tmp;
	long long   num;

	if (*n < 0ll)
		*n *= -1;
	*len = 0;
	num = *n;
	while (num > 0ll)
	{
		*len += 1;
		num /= 16;
	}
	tmp = malloc(*len + 1);
	return(tmp);
}

static char		*is_zero()
{
	char *tmp;

	tmp = malloc(2);
	tmp[0] = '0';
	tmp[1] = 0;
	return (tmp);
}

char		*ft_itox(long long n, char alpha)
{
	char	*ans;
	int		len;

	if (n == 0)
		return (is_zero());
	ans = (char *)init(&n, &len);
	ans[len--] = 0;
	while (n > 0)
	{
		if ((n % 16) < 10)
			ans[len--] =  n % 16 + '0';
		else
			ans[len--] =  n % 16 - 10 + alpha;
		n /= 16;
	}
	return (ans);
}

int		print_x(t_list node, unsigned int num)
{
	char	*print;
	size_t	print_container;
	size_t	print_width;
	char	*str_container;
	char	*str_width;

	// if (node.length < 0)
	// 	node.length = 0;

	// print = ft_itox((long long)num, 'a');


	// print_container = ft_max(ft_strlen(print), node.length);
	// print_width = ft_max(print_container, node.width);

	///
	if (node.length == 0 && num == 0 && node.precision == '.')
		print = make_zero();
	else
		print = ft_itox((long long)num, 'a');
	
	if (node.length < 0)
	{
		node.length = 0;
		node.precision = 0;
	}

	print_container = ft_max(ft_strlen(print), node.length);
	if (num < 0)
		print_width = ft_max(print_container + 1, node.width);
	else
		print_width = ft_max(print_container, node.width);

	if (node.flag == '0' && node.precision != '.')
	{
		if (num < 0)
			print_container = print_width - 1;
		else
			print_container = print_width;
	}

	///



	str_container = (char *)malloc(print_container);
	str_width = (char *)malloc(print_width + 1);

	if (node.flag == '0' || node.length > 0)
		set_zero(str_container, print_container);
	else
		ft_setspace(str_container, print_container + 1);
	ft_setspace(str_width, print_width + 1);
	str_width[print_width] = 0;

	ft_memmove(&str_container[print_container - ft_strlen(print)], print, ft_strlen(print));
	free(print);
	if (node.flag == '-')
		ft_memmove(&str_width[0], str_container, print_container);
	else
		ft_memmove(&str_width[print_width - print_container], str_container, print_container);
	free(str_container);

	ft_putstr_fd(str_width, 1);
	free(str_width);

	return (print_width);
}

int		print_X(t_list node, unsigned int num)
{
	char	*print;
	size_t	print_container;
	size_t	print_width;
	char	*str_container;
	char	*str_width;
	
	// if (node.length < 0)
	// 	node.length = 0;
	// print = ft_itox((long long)num, 'A');
	// print_container = ft_max(ft_strlen(print), node.length);
	// print_width = ft_max(print_container, node.width);

	//
	if (node.length == 0 && num == 0 && node.precision == '.')
		print = make_zero();
	else
		print = ft_itox((long long)num, 'A');
	
	if (node.length < 0)
	{
		node.length = 0;
		node.precision = 0;
	}

	print_container = ft_max(ft_strlen(print), node.length);
	if (num < 0)
		print_width = ft_max(print_container + 1, node.width);
	else
		print_width = ft_max(print_container, node.width);

	if (node.flag == '0' && node.precision != '.')
	{
		if (num < 0)
			print_container = print_width - 1;
		else
			print_container = print_width;
	}
	//

	str_container = (char *)malloc(print_container);
	str_width = (char *)malloc(print_width + 1);

	if (node.flag == '0' || node.length > 0)
		set_zero(str_container, print_container);
	else
		ft_setspace(str_container, print_container + 1);
	ft_setspace(str_width, print_width + 1);
	str_width[print_width] = 0;

	ft_memmove(&str_container[print_container - ft_strlen(print)], print, ft_strlen(print));
	free(print);
	if (node.flag == '-')
		ft_memmove(&str_width[0], str_container, print_container);
	else
		ft_memmove(&str_width[print_width - print_container], str_container, print_container);
	free(str_container);

	ft_putstr_fd(str_width, 1);
	free(str_width);

	return (print_width);
}

