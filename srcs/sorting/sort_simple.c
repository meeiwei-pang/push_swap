/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:48:34 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/08 15:48:34 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*if target at top half ra, else rra*/
static void	bring_to_top(t_node **a, int target, t_ctx *context)
{
	int	distance;
	int	size;

	distance = get_distance(*a, target);
	size = ft_lstsize(*a);
	if (distance <= size / 2)
	{
		while (distance > 0)
		{
			ra(a, context);
			distance--;
		}
	}
	else
	{
		distance = size - distance;
		while (distance > 0)
		{
			rra(a, context);
			distance--;
		}
	}
}

void	sort_simple(t_node **a, t_node **b, t_ctx *context)
{
	int	target;

	target = 0;
	while (*a)
	{
		bring_to_top(a, target, context);
		pb (a, b, context);
		target++;
	}
	while (*b)
		pa (a, b, context);
}