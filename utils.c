/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 03:13:42 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/10 16:21:16 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_main(t_stack *a, t_stack *b)
{
	ft_free_stack(a);
	ft_free_stack(b);
}

void	ft_free_stack(t_stack *stack)
{
	free(stack->arr);
	free(stack);
}

void	ft_error_exit(void)
{
	write(2, "error\n", 6);
	exit(EXIT_FAILURE);
}
