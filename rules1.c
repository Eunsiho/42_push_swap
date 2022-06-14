/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:07:30 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/09 14:29:01 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (a->size < 2)
		return ;
	ft_c_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	if (b->size < 2)
		return ;
	ft_c_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_c_swap(a);
	ft_c_swap(b);
	ft_putstr_fd("ss\n", 1);
}
