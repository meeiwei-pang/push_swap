/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:37:46 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/02 08:05:00 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *s, int *num)
{
	long	result;
	long	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++; //do we actually have to check for whitespace? 
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		result = (result * 10) + s[i] - '0';
		i++;
	}
	result = result * sign;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return (*num = (int)result, 1);
}

int	is_duplicate(t_node *node, int n)
{
	if (!node)
		return (0);
	while (node)
	{
		if (node->value == n)
			return (1);
		node = node->next;
	}
	return (0);
}
