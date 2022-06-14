/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:13 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/14 15:26:44 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_c_r_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size < 2)
		return ;
	temp = stack->arr[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->size - 1] = temp;
}

void	ft_c_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size < 2)
		return ;
	temp = stack->arr[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = temp;
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
