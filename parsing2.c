/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:39:12 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/14 10:01:45 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(int *arr, int count)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_convert2indexed(t_stack *a, t_stack *index)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < index->size)
		{
			if (a->arr[i] == index->arr[j])
			{
				a->arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_reverse_array_int(int *arr, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		temp = arr[i];
		arr[i] = arr[(size - 1) - i];
		arr[(size - 1) - i] = temp;
		i++;
	}
}

void	ft_make_stack_a(t_stack *a, int argc, char *argv[])
{
	t_stack	*index;

	ft_init_stack(&index);
	ft_take_args_raw(index, argc, argv);
	ft_bubble_sort(index->arr, index->size);
	ft_take_args_raw(a, argc, argv);
	ft_reverse_array_int(a->arr, a->size);
	ft_convert2indexed(a, index);
	ft_free_stack(index);
}
