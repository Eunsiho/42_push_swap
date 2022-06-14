/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:19:47 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/14 10:28:32 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	size;
	int	capacity;
	int	*arr;
}	t_stack;

// parsing
void	ft_make_stack_a(t_stack *a, int argc, char *argv[]);
void	ft_take_args_raw(t_stack *indexed, int argc, char *argv[]);
void	ft_indexing(t_stack *stack, int argc, char *argv[]);

// utils
void	ft_exit_main(t_stack *a, t_stack *b);
void	ft_error_exit(void);
void	ft_free_stack(t_stack *stack);

// stack
void	ft_init_stack(t_stack **stack);
void	ft_push(t_stack *stack, int data);
int		ft_pop(t_stack *stack);

// commands
void	ft_c_swap(t_stack *stack);
void	ft_c_push(t_stack *from, t_stack *to);
void	ft_c_rotate(t_stack *stack);
void	ft_c_r_rotate(t_stack *stack);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// sort
void	ft_sort_to3(t_stack *a);
void	ft_sort_4to5(t_stack *a, t_stack *b);
void	ft_sort_over5(t_stack *a, t_stack *b);

void	ft_sort_and_print(t_stack *a, t_stack *b);

// sort utils
int		ft_isreversesorted(t_stack *a);
int		ft_issorted(t_stack *a);
int		ft_search_index(t_stack *stack, int n);

#endif