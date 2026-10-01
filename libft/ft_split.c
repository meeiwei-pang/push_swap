/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:59:40 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/01 11:46:06 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_array(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	free_array(char **array, size_t array_index)
{
	while (array_index > 0)
	{
		array_index--;
		free(array[array_index]);
	}
	free(array);
}

static int	malloc_fail(char **array, size_t array_index)
{
	if (!array[array_index])
	{
		free_array(array, array_index);
		return (1);
	}
	return (0);
}

static char	**fill_in(char **array, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	array_index;

	i = 0;
	array_index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			array[array_index] = ft_substr(s, start, i - start);
			if (malloc_fail(array, array_index))
				return (NULL);
			array_index++;
		}
		else
			i++;
	}
	array[array_index] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	size;

	if (!s)
		return (NULL);
	size = count_array(s, c) + 1;
	array = malloc(sizeof(char *) * size);
	if (!array)
		return (NULL);
	array = fill_in(array, s, c);
	return (array);
}

