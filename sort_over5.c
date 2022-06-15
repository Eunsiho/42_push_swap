/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:41:49 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 13:49:23 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_from_bottom(t_stack *a, int chunk)
{
	int	i;

	i = 0;
	while (i < a->size / 2)
	{
		if (0 <= a->arr[a->size - 1 - i]
			&& a->arr[a->size - 1 - i] <= chunk)
			return (0);
		i++;
	}
	return (1);
}

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
	int	i;

	while (b->size)
	{
		from_top = ft_from_top(b, b->size - 1);
		from_bottom = ft_from_bottom(b, b->size - 1);
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
	int	from_bottom;

	from_bottom = ft_if_from_bottom(a, chunk);
	while (a->size)
	{
		if (a->arr[a->size - 1] <= b->size)
			pb(a, b);
		else if (a->arr[a->size - 1] <= b->size + chunk)
		{
			pb(a, b);
			rb(b);
		}
		else if (from_bottom)
			rra(a);
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
		chunk = 15;
	else if(size <= 500)
		chunk = 30;
	ft_push2b(a, b, chunk);
	ft_push2a(a, b);
}
