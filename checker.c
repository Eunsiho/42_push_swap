/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:52:35 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/15 17:18:47 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_command(t_stack *a, t_stack *b, char *s)
{
	if (!ft_strncmp(s, "sa\n", 4))
		sa_c(a);
	else if(!ft_strncmp(s, "sb\n", 4))
		sb_c(b);
	else if(!ft_strncmp(s, "ss\n", 4))
		ss_c(a, b);
	else if(!ft_strncmp(s, "pa\n", 4))
		pa_c(a, b);
	else if(!ft_strncmp(s, "pb\n", 4))
		pb_c(a, b);
	else if(!ft_strncmp(s, "ra\n", 4))
		ra_c(a);
	else if(!ft_strncmp(s, "rb\n", 4))
		rb_c(b);
	else if(!ft_strncmp(s, "rr\n", 4))
		rr_c(a, b);
	else if(!ft_strncmp(s, "rra\n", 4))
		rra_c(a);
	else if(!ft_strncmp(s, "rrb\n", 4))
		rrb_c(b);
	else if(!ft_strncmp(s, "rrr\n", 4))
		rrr_c(a, b);
	else
		ft_error_exit();
}

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	char	*s;
	
	if (argc < 2)
		return (0);
	ft_init_stack(&a, 500);
	ft_make_stack_a(a, argc, argv);
	ft_init_stack(&b, a->capacity);
	s = get_next_line(0);
	while (s)
	{
		ft_put_command(a, b, s);
		free(s);
		s = get_next_line(0);
	}
	if (ft_issorted(a) && !b->size)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}