/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:56:25 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/14 15:20:42 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// void	print_stack(t_stack *stack)
// {
// 	int	i;

// 	i = stack->size - 1;
// 	while (i >= 0)
// 	{
// 		printf("[%d] : %d\n", i, stack->arr[i]);
// 		i--;
// 	}
// }

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	ft_init_stack(&a, 500);
	ft_make_stack_a(a, argc, argv);
	ft_init_stack(&b, a->capacity);
	ft_sort_and_print(a, b);
	ft_exit_main(a, b);
	return (0);
}
