/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:57:20 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 16:57:24 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	number_of_substrings(char const *s, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			count = 1;
			index++;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (index);
}

static char	*copy_word(const char *s, int start, int finish)
{
	int		index;
	char	*substring;

	index = 0;
	substring = malloc((finish - start + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (start < finish)
		substring[index++] = s[start++];
	substring[index] = '\0';
	return (substring);
}

static char	**cleanup_strings(char **strings, size_t j)
{
	while (j > 0)
	{
		j--;
		free(strings[j]);
	}
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**strings;
	size_t	i;
	size_t	j;

	index = -1;
	i = -1;
	j = 0;
	strings = malloc((number_of_substrings(s, c) + 1) * sizeof(char *));
	if (!s || !strings)
		return (0);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			strings[j] = copy_word(s, index, i);
			if (strings[j++] == NULL)
				return (cleanup_strings(strings, j -1));
			index = -1;
		}
	}
	strings[j] = 0;
	return (strings);
}
