/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:14:57 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/09 14:40:59 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_node **a, t_node **b, t_ctx *context)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = ft_lstsize(*a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i & 1) == 0)
				pb(a, b, context);
			else
				ra(a, context);
			j++;
		}
		while (*b)
			pa(a, b, context);
		i++;
	}
}
