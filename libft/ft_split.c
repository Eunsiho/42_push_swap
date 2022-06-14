/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:12:14 by hogkim            #+#    #+#             */
/*   Updated: 2022/06/07 03:10:56 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**words_clear(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

int	word_count(char const *s)
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

char	**words_dup(char const *s, char **words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i] && j < word_count(s))
	{
		while (s[i] && if_whitespace(s[i]))
			i++;
		len = 0;
		while (s[i] && !if_whitespace(s[i]))
		{
			len++;
			i++;
		}
		words[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!words[j])
		{
			words_clear(words);
			return (NULL);
		}
		ft_strlcpy(words[j++], s + (i - len), len + 1);
	}
	return (words);
}

char	**ft_split(char const *s)
{
	char	**words;
	int		count;

	if (!s)
		return (NULL);
	count = word_count(s);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	words = words_dup(s, words);
	if (!words)
		return (NULL);
	words[count] = NULL;
	return (words);
}
