/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:09:05 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/09 13:53:31 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!b->size)
		return ;
	ft_c_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->size)
		return ;
	ft_c_push(a, b);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	ft_c_rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	if (b->size < 2)
		return ;
	ft_c_rotate(b);
	ft_putstr_fd("rb\n", 1);
}
