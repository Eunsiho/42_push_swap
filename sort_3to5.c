/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3to5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:18:21 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/14 10:11:14 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_top_and_push(t_stack *a, t_stack *b, int aim)
{
	if (aim == 0)
	{
		rra(a);
		pb(a, b);
	}
	else if (aim == 1)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (aim == a->size - 2)
	{
		ra(a);
		pb(a, b);
	}
	else if (aim == a->size - 1)
		pb(a, b);
	else
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
}

void	ft_sort_4to5_into_b(t_stack *a, t_stack *b)
{
	int	aim2push;

	aim2push = ft_search_index(a, 0);
	ft_make_top_and_push(a, b, aim2push);
	if (a->size == 3)
		return ;
	aim2push = ft_search_index(a, 1);
	ft_make_top_and_push(a, b, aim2push);
}

void	ft_sort_4to5(t_stack *a, t_stack *b)
{
	ft_sort_4to5_into_b(a, b);
	ft_sort_to3(a);
	while (b->size)
		pa(a, b);
}

void	ft_sort_to3(t_stack *a)
{
	if (ft_issorted(a))
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->arr[0] > a->arr[2] && a->arr[1] > a->arr[0])
	{
		rra(a);
		sa(a);
	}
	else if (a->arr[2] > a->arr[1] && a->arr[0] > a->arr[2])
		sa(a);
	else if (a->arr[2] > a->arr[0] && a->arr[1] > a->arr[2])
		rra(a);
	else if (a->arr[0] > a->arr[1] && a->arr[2] > a->arr[0])
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}
