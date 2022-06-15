/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:09:05 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 14:19:27 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_c(t_stack *a, t_stack *b)
{
	if (!b->size)
		return ;
	ft_c_push(b, a);
}

void	pb_c(t_stack *a, t_stack *b)
{
	if (!a->size)
		return ;
	ft_c_push(a, b);
}

void	ra_c(t_stack *a)
{
	if (a->size < 2)
		return ;
	ft_c_rotate(a);
}

void	rb_c(t_stack *b)
{
	if (b->size < 2)
		return ;
	ft_c_rotate(b);
}
