/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:56:25 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/13 15:36:08 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	ft_init_stack(&a);
	ft_init_stack(&b);
	ft_make_stack_a(a, argc, argv);
	ft_sort_and_print(a, b);
	ft_exit_main(a, b);
	return (0);
}
