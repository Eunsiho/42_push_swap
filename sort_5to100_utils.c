/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5to100_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:07:23 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/13 15:45:08 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_save_next_aim(t_stack *a, t_stack *b, int aim)
{
	if (b->arr[b->size -1] == aim - 2 || b->arr[b->size -1] == aim - 3)
	{
		pa(a, b);
		ra(a);
	}
} // b에 다음 aim 혹은 다다음 aim 이 존재한다면 a의 바닥에 넣어두기.

void	ft_get_aim_top(t_stack *a, t_stack *b, int *aim)
{
	while (a->arr[a->size -1] != *aim)
	{
		if (b->size == 1)
		{
			pa(a, b);
			break;
		}
		if (ft_get_from_a(a, b, aim)) // ?
			return ;
		ft_save_next_aim(a, b, *aim);
		if (b->arr[b->size - 1] == *aim || b->arr[b->size - 1] == *aim - 1)
		{
			pa(a, b);
			if (a->arr[a->size - 1] == *aim - 1)
				continue ;
			if (a->arr[a->size - 1] > a->arr[a->size - 2])
				sa(a);
			if (a->arr[a->size - 1] == *aim || a->arr[a->size - 1] == *aim - 1)
			{
				*aim = a->arr[a->size - 1] - 1;
				return ;
			}
		}
		rb(b);
	}
}

void	ft_get_aim_bottom(t_stack *a, t_stack *b, int *aim)
{
	while (a->arr[a->size -1] != *aim)
	{
		if (b->size == 1)
		{
			pa(a, b);
			break;
		}
		if (ft_get_from_a(a, b, aim)) // ?
			return ;
		ft_save_next_aim(a, b, *aim);
		if (b->arr[b->size - 1] == *aim || b->arr[b->size - 1] == *aim - 1)
		{
			pa(a, b);
			if (a->arr[a->size - 1] == *aim - 1)
				continue ;
			if (a->arr[a->size - 1] > a->arr[a->size - 2])
				sa(a);
			if (a->arr[a->size - 1] == *aim || a->arr[a->size - 1] == *aim - 1)
			{
				*aim = a->arr[a->size - 1] - 1;
				return ;
			}
		}
		rrb(b);
	}
}

int	ft_get_aim_from_ends(t_stack *a, t_stack *b, int *aim)
{ // b스택의 top혹은 bottom에 aim이 있을 때 pa해줌.
	if (b->arr[b->size - 1] != *aim && b->arr[0] != *aim) // b스택의 top혹은 bottom에 aim이 없다면.
		return (0);
	if (b->arr[b->size - 1] == *aim) // aim이 b의 top일 때.
		pa(a, b);
	else // aim이 b의 bottom일 때.
	{
		rrb(b);
		pa(a, b);
	}
	*aim = a->arr[a->size - 1];
	return (1);
}

int	ft_get_from_a(t_stack *a, t_stack *b, int *aim)
{
	if (ft_find_aim(a, *aim) != -1) // aim이 a스택에 존재한다면.
	{
		while (a->arr[0] != *aim)  // a스택의 bottom이 aim이라면 멈춘다.
		{ // a 스택의 bottom이 aim이 아니라면 그것을 맨 위로 올려서 pb한다.
			rra(a);
			pb(a, b);
		}
		if (a->arr[0] == *aim)
		{ // bottom에 aim이 안착했다면 rra 해서 맨 위로 올린뒤 그 다음 에임을 목표로 바꾼다.
			rra(a);
			(*aim)--;
			return (1);
		}
	}
	return (0);
} // a스택 내에서 aim이 a스택에 존재할 때 aim을 탑으로 만들어주는 함수.