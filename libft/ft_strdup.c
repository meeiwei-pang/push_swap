/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:13:36 by ibishak           #+#    #+#             */
/*   Updated: 2026/09/28 10:40:03 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, len + 1);
	return (dst);
}

