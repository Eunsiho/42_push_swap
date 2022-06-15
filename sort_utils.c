/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:50:53 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 16:50:28 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra_is_better(t_stack *a, t_stack *b, int chunk)
{
	int	i;

	i = 0;
	while (i < a->size / 2)
	{
		if (b->size <= a->arr[a->size - 1 - i]
			&& a->arr[a->size - 1 - i] <= chunk + b->size)
			return (i);
		i++;
	}
	return (0);
}

int	ft_issorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_search_index(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] == n)
			return (i);
		i++;
	}
	return (0);
}
