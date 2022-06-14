/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:21:07 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/10 19:29:32 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_expand_arr(int *arr, int cur_size)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * cur_size * 2);
	if (!temp)
		ft_error_exit();
	ft_memcpy(temp, arr, cur_size);
	free(arr);
	arr = temp;
}

int	ft_pop(t_stack *stack)
{
	int	data;

	data = stack->arr[stack->size - 1];
	stack->size--;
	return (data);
}

void	ft_push(t_stack *stack, int data)
{
	stack->arr[stack->size] = data;
	stack->size++;
	if (stack->size == stack->capacity)
		ft_expand_arr(stack->arr, stack->size);
}

void	ft_init_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack))
		ft_error_exit();
	(*stack)->arr = (int *)malloc(sizeof(int) * 100);
	if (!(*stack)->arr)
	{
		free(stack);
		ft_error_exit();
	}
	(*stack)->size = 0;
	(*stack)->capacity = 100;
}
