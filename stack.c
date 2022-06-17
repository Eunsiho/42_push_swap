/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:21:07 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/17 10:52:15 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_expand_arr(t_stack *stack, int cur_size)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * cur_size * 2);
	if (!temp)
		ft_error_exit();
	ft_memcpy(temp, stack->arr, sizeof(int) * cur_size);
	free(stack->arr);
	stack->arr = temp;
	stack->capacity = cur_size * 2;
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
		ft_expand_arr(stack, stack->capacity);
}

void	ft_init_stack(t_stack **stack, int size)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack))
		ft_error_exit();
	(*stack)->arr = (int *)malloc(sizeof(int) * size);
	if (!(*stack)->arr)
	{
		free(stack);
		ft_error_exit();
	}
	(*stack)->size = 0;
	(*stack)->capacity = size;
}
