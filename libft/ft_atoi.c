/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:27:13 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/07 02:54:40 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_range(long long int n)
{
	if (n > 2147483647 || n < -2147483648)
		ft_error_exit();
}

void	ft_isvalid(char c)
{
	if (!c)
		ft_error_exit();
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	long long int	value;

	sign = 1;
	value = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	ft_isvalid(str[i]);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error_exit();
		value = 10 * value + str[i++] - '0';
	}
	value *= sign;
	ft_int_range(value);
	return ((int)value);
}
