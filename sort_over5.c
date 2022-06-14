/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:41:49 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/14 10:27:14 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push2a(t_stack *a, t_stack *b, int chunk)
{
	int	i;

	i = 0;
	while (i < chunk)
	{
		if (b->arr[b->size - 1 - i] == b->size - 1)
			rb(b);
		else if (b->arr[i] == b->size - 1)
			rrb(b);
		if (b->arr[b->size - 1] == b->size - 1)
			break ;
		i++;
	}
	pa(a, b);
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

int	ft_make_chunk(int size)
{
	int	chunk;
	int	constant;

	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	return (chunk);
}

void	ft_sort_over5(t_stack *a, t_stack *b)
{
	int	chunk;

	chunk = ft_make_chunk(a->size);
	ft_push2b(a, b, chunk);
	ft_push2a(a, b, chunk);
}
