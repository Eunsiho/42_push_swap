/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:10:34 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 14:20:07 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_c(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_c_rotate(a);
	ft_c_rotate(b);
}

void	rra_c(t_stack *a)
{
	if (a->size < 2)
		return ;
	ft_c_r_rotate(a);
}

void	rrb_c(t_stack *b)
{
	if (b->size < 2)
		return ;
	ft_c_r_rotate(b);
}

void	rrr_c(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_c_r_rotate(a);
	ft_c_r_rotate(b);
}
