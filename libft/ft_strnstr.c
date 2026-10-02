/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:46:25 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/02 08:02:42 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *tiny, size_t len)
{
	size_t	big_i;
	size_t	tiny_i;
	size_t	j;

	big_i = 0;
	tiny_i = 0;
	j = 0;
	if (tiny[tiny_i] == '\0')
		return ((char *)big);
	while (j < len && big[big_i + j])
	{
		big_i = 0;
		tiny_i = 0;
		while ((big_i + j) < len && tiny[tiny_i]
			&& big[big_i + j] == tiny[tiny_i])
		{
			big_i++;
			tiny_i++;
		}
		if (tiny[tiny_i] == '\0')
			return ((char *)big + j);
		j++;
	}
	return (NULL);
}
