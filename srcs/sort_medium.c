/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:41:18 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/08 18:41:18 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int n)
{
	int	root;

	root = 1;
	while ((root + 1) * (root + 1) <= n)
		root++;
	return (root);
}

static void	push_chunks(t_node **a, t_node **b, int chunk, t_ctx *context)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b, context);
			rb(b, context);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk)
		{
			pb(a, b, context);
			pushed++;
		}
		else
			ra(a, context);
	}
}

static void	bring_b_to_top(t_node **b, int target, t_ctx *context)
{
	int	distance;
	int	size;

	distance = get_distance(*b, target);
	size = ft_lstsize(*b);
	if (distance <= size / 2)
	{
		while (distance > 0)
		{
			rb(b, context);
			distance--;
		}
	}
	else
	{
		distance = size - distance;
		while (distance > 0)
		{
			rrb(b, context);
			distance--;
		}
	}
}

void	sort_medium(t_node **a, t_node **b, t_ctx *context)
{
	int	size;

	size = ft_lstsize(*a);
	push_chunks(a, b, chunk_size(size), context);
	while (*b)
	{
		bring_b_to_top(b, ft_lstsize(*b) - 1, context);
		pa(a, b, context);
	}
}