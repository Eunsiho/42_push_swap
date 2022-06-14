/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:13 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/07 09:55:40 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_c_r_rotate(t_stack *stack)
{
	int	*temp;

	if (stack->size < 2)
		return ;
	temp = (int *)malloc(sizeof(int) * stack->capacity);
	if (!temp)
		ft_error_exit();
	ft_memcpy(temp, stack->arr + 1, (stack->size - 1) * sizeof(int));
	temp[stack->size - 1] = stack->arr[0];
	free(stack->arr);
	stack->arr = temp;
}

void	ft_c_rotate(t_stack *stack)
{
	int	*temp;

	if (stack->size < 2)
		return ;
	temp = (int *)malloc(sizeof(int) * stack->capacity);
	if (!temp)
		ft_error_exit();
	ft_memcpy(temp + 1, stack->arr, (stack->size - 1) * sizeof(int));
	temp[0] = stack->arr[stack->size - 1];
	free(stack->arr);
	stack->arr = temp;
}

void	ft_c_push(t_stack *from, t_stack *to)
{
	int	data;

	if (!from->size)
		return ;
	data = ft_pop(from);
	ft_push(to, data);
}

void	ft_c_swap(t_stack *stack)
{
	int	temp;
	int	top;

	if (stack->size < 2)
		return ;
	top = stack->size - 1;
	temp = stack->arr[top];
	stack->arr[top] = stack->arr[top - 1];
	stack->arr[top - 1] = temp;
}
