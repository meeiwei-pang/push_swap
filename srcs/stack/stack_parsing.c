/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:37:46 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/16 13:07:21 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	read_digits(const char *s, long *result)
{
	int	i;

	i = 0;
	if (s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		*result = (*result * 10) + (s[i] - '0');
		if (*result > (long)INT_MAX + 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atol(const char *s, int *num)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	if (!read_digits(&s[i], &result))
		return (0);
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
