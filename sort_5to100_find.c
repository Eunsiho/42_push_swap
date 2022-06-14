/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5to100_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:08:43 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/13 13:58:45 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_aim_from_top(t_stack *stack, int aim, int min)
{ // aim을 top에서부터 내려오며 있는지 찾음.
	int	i;

	i = stack->size - 1;
	while (i >= 0)
	{
		if (stack->arr[i] == aim || stack->arr[i] < min)
			break;
		i--;
	}
	if (stack->arr[i] != aim)
		return (-1);
	return (1);
}

int	ft_find_aim_from_bottom(t_stack *stack, int aim, int min)
{ // aim을 bottom에서부터 올라가며 있는지 찾음.
	int	i;

	i = 0;
	while (i < (stack->size - 1))
	{
		if (stack->arr[i] == aim || stack->arr[i] < min)
			break;
		i++;
	}
	if (stack->arr[i] != aim)
		return (-1);
	return (1);
}

int	ft_find_aim(t_stack *stack, int aim)
{ // aim이 stack a에 존재 하는지 찾음.
	int	i;

	i = 0;
	while (i < (stack->size - 1))
	{
		if (stack->arr[i] == aim)
			break;
		i++;
	}
	if (stack->arr[i] != aim)
		return (-1);
	return (i);
}