/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:41:49 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 16:51:30 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_from_top(t_stack *b, int aim)
{
	int	i;

	i = 0;
	while (i < b->size / 2)
	{
		if (b->arr[b->size - 1 - i] == aim)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_from_bottom(t_stack *b, int aim)
{
	int	i;

	i = 0;
	while (i < b->size / 2)
	{
		if (b->arr[i] == aim)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_push2a(t_stack *a, t_stack *b)
{
	int	from_top;
	int	from_bottom;

	while (b->size)
	{
		from_top = ft_from_top(b, b->size - 1);
		from_bottom = ft_from_bottom(b, b->size - 1);
		if (from_bottom > from_top)
		{
			while (b->arr[b->size - 1] != b->size - 1)
				rrb(b);
		}
		else
		{
			while (b->arr[b->size - 1] != b->size - 1)
				rb(b);
		}
		pa(a, b);
	}
}

void	ft_push2b(t_stack *a, t_stack *b, int chunk)
{
	int	ra_is_better;

	ra_is_better = ft_ra_is_better(a, b, chunk);
	while (a->size)
	{
		if (a->arr[a->size - 1] <= b->size)
			pb(a, b);
		else if (a->arr[a->size - 1] <= b->size + chunk)
		{
			pb(a, b);
			rb(b);
		}
		else if (!ra_is_better && chunk > 25)
		{
			rra(a);
			ra_is_better = ft_ra_is_better(a, b, chunk);
		}
		else
			ra(a);
	}
}

void	ft_sort_over5(t_stack *a, t_stack *b)
{
	int	chunk;
	int	size;

	size = a->size;
	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	if (size <= 100)
		chunk = 13;
	else if (size <= 500)
		chunk = 30;
	ft_push2b(a, b, chunk);
	ft_push2a(a, b);
}
