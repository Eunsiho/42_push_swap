/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:56:25 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/17 10:50:15 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	ft_init_stack(&a, 500);
	ft_make_stack_a(a, argc, argv);
	ft_init_stack(&b, a->capacity);
	ft_sort_and_print(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	while (1);
	return (0);
}
