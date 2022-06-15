/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:07:30 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 14:19:15 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_c(t_stack *a)
{
	if (a->size < 2)
		return ;
	ft_c_swap(a);
}

void	sb_c(t_stack *b)
{
	if (b->size < 2)
		return ;
	ft_c_swap(b);
}

void	ss_c(t_stack *a, t_stack *b)
{
	if (a->size < 2 && b->size < 2)
		return ;
	ft_c_swap(a);
	ft_c_swap(b);
}
