/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:33:49 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/02 08:02:53 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && check(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && check(s1[end - 1], set))
		end--;
	result = malloc(end - start + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1 + start, end - start);
	result[end - start] = '\0';
	return (result);
}

