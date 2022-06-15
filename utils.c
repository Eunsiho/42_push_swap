/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 03:13:42 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 13:54:45 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
