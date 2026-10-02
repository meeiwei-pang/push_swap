/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:23:44 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/02 08:02:47 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*last_pos;

	last_pos = NULL;
	while (*str)
	{
		if (*str == (char)ch)
			last_pos = (char *)str;
		str++;
	}
	if ((char)ch == '\0')
		last_pos = (char *)str;
	return (last_pos);
}
