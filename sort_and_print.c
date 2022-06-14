/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:07:35 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/13 15:36:15 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_and_print(t_stack *a, t_stack *b)
{
	if (ft_issorted(a))
		return ;
	else if (a->size < 4)
		ft_sort_to3(a);
	else if (a->size < 6)
		ft_sort_4to5(a, b);
	else if (a->size < 101)
		ft_sort_5to100(a, b);
	// else
	// 	ft_sort_over101(a, b);
	else
		return ;
}
