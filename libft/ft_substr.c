/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:11:43 by ibishak           #+#    #+#             */
/*   Updated: 2026/09/28 10:38:32 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_dst(void)
{
	char	*dst;

	dst = malloc(1);
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	size_t			i;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (empty_dst());
	if (len > s_len - start)
		len = s_len - start;
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

