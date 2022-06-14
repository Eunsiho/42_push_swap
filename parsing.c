/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:58:47 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/10 16:24:10 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	ft_word_count(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && if_whitespace(s[i]))
			i++;
		else
		{
			count++;
			while (s[i] && !if_whitespace(s[i]))
				i++;
		}
	}
	return (count);
}

void	ft_isunique(t_stack *stack, int data, char **words)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] == data)
		{
			ft_free_stack(stack);
			ft_free_words(words);
			ft_error_exit();
		}
		i++;
	}
}

void	ft_take_args_raw(t_stack *stack, int argc, char *argv[])
{
	int		i;
	int		j;
	int		temp;
	int		word_count;
	char	**words;

	i = 0;
	while (++i < argc)
	{
		word_count = ft_word_count(argv[i]);
		if (!word_count)
		{
			ft_free_stack(stack);
			ft_error_exit();
		}
		words = ft_split(argv[i]);
		j = -1;
		while (++j < word_count)
		{
			temp = ft_atoi(words[j]);
			ft_isunique(stack, temp, words);
			ft_push(stack, temp);
		}
		ft_free_words(words);
	}
}
