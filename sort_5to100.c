/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5to100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:23:03 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/13 16:27:38 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_take_remainders(t_stack *a, t_stack *b, int max)
{
	while (a->arr[0] == a->arr[a->size - 1] -1
			|| a->arr[0] == a->arr[a->size - 1] - 2
			|| a->arr[0] == 0 || a->arr[0] == 1)
	{
		rra(a);
		if (a->arr[a->size - 1] > a->arr[a->size - 2])
			sa(a);
	}
	if (b->arr[b->size - 1] == max)
	{
		pa(a, b);
		ra(a);
	}
}

void	ft_sort_stack_b(t_stack *a, t_stack *b, int min) //min과 max는 ㄷ,ㄹ의 최대 최소값.
{
	int	aim;
	int	i;
	int	j;

	if (a->size > 1)
	{
		while (a->arr[a->size - 1] != a->arr[a->size - 2] - 1)
			ra(a);
	} // 큰 함수 할때 쓰기위해 예외처리.
	aim = a->arr[a->size - 1] - 1; // 찾으려는 값...!
	while (aim >= min && b->size) // min은 ㄷ,ㄹ에서의 최소값이다. 다 정렬 되고나면 더이상 돌필요가없다.
	{
		if (ft_get_from_a(a, b, &aim)) // a스택 내에서 aim을 탑으로 올리는 것을 반복하는 함수.
			continue;
		i = ft_find_aim_from_top(b, aim, min);
		j = ft_find_aim_from_bottom(b, aim, min);
		if (i == 0 || j == 0)
			ft_get_aim_from_ends(a, b, &aim);
		else if (i == -1 || (j != -1 && j < i))
			ft_get_aim_bottom(a, b, &aim);
		else
			ft_get_aim_top(a, b, &aim);
	}

}

void	ft_sort_stack_a(t_stack *a, t_stack *b, int min, int max)
{ 
	while (1) // a에 3개 원소가 남을 때 까지 @@
	{
		if (a->size == 3) // 3개 남았다면 정렬
			ft_sort_to3(a);
		if (ft_issorted(a)) // 정렬되었다면 끝
			break ;
		if (a->arr[a->size - 1] >= max - 2) // a의 탑 가장 큰 숫자 세가지라면 a스택의 바닥에 깔아주기.
			ra(a);
		else
		{
			pb(a, b); // 가장 큰 숫자 세가지가 아니라면 b로 넘기기. 그리고기min과 max의 중간값보다 작다면 아래로 깔기.
			if (b->arr[b->size - 1] < min + (max + min) / 2) 
				rb(b);
		}
	} // 현재 a에 가장 큰 숫자 세개가 정렬되었거나, 더 정렬 되어 있는 상태. @
	ft_sort_stack_b(a, b, min);
}

void	ft_push_half2b(t_stack *a, t_stack *b, int size)
{
	int	i;

	i = 0;
	while (a->size > size / 2)
	{
		if (a->arr[a->size - 1] < size / 2)
		{
			pb(a, b);
			if (b->arr[b->size - 1] < size / 4)
				rb(b);
		}
		else
			ra(a);
	}
}

void	ft_sort_5to100(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	ft_push_half2b(a, b, size);
	ft_sort_stack_a(a, b, size / 2, size - 1);
}