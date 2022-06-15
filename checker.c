/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:52:35 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 13:55:20 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	
	ft_init_stack(&a, 500);
	ft_make_stack_a(a, argc, argv);
	ft_init_stack(&b, a->capacity);
}