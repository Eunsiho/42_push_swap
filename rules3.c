/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:10:34 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/09 13:54:02 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_c_rotate(a);
	ft_c_rotate(b);
	ft_putstr_fd("rr\n", 1);
}

void	rra(t_stack *a)
{
	if (a->size < 2)
		return ;
	ft_c_r_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	if (b->size < 2)
		return ;
	ft_c_r_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_c_r_rotate(a);
	ft_c_r_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
