/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:41:49 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/14 16:23:23 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_from_top(t_stack *b, int aim, int chunk)
{
	int	i;

	i = 0;
	while (i < chunk)
	{
		if (b->arr[b->size - 1 - i] == aim)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_from_bottom(t_stack *b, int aim, int chunk)
{
	int	i;

	i = 0;
	while (i < chunk)
	{
		if (b->arr[i] == aim)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_push2a(t_stack *a, t_stack *b, int chunk)
{
	int	from_top;
	int	from_bottom;
	int	i;

	while (b->size)
	{
		from_top = ft_from_top(b, b->size - 1, chunk);
		from_bottom = ft_from_bottom(b, b->size - 1, chunk);
		if (from_bottom > from_top)
		{
			i = -2;
			while (++i < from_bottom)
				rrb(b);
		}
		else
		{
			i = -1;
			while (++i < from_top)
				rb(b);
		}
		pa(a, b);
	}
}

void	ft_push2b(t_stack *a, t_stack *b, int chunk)
{
	while (a->size)
	{
		if (a->arr[a->size - 1] <= b->size)
			pb(a, b);
		else if (a->arr[a->size - 1] <= b->size + chunk)
		{
			pb(a, b);
			rb(b);
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
	ft_push2b(a, b, chunk);
	ft_push2a(a, b, chunk);
}
