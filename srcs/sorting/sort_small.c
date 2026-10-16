/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:05:01 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/16 12:34:13 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_3(t_node **stack, t_ctx *context)
{
	t_node	*max_node;

	if (!stack || !*stack)
		return ;
	max_node = find_max(*stack);
	if (max_node == *stack)
		ra(stack, context);
	else if (max_node == (*stack)->next)
		rra(stack, context);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, context);
}

static void	sort4and5(t_node **a, t_node **b, t_ctx *context)
{
	t_node	*min_node;
	int		pos;
	int		size;

	if (!a || !*a)
		return ;
	while (stack_size(*a) > 3)
	{
		min_node = find_min(*a);
		pos = get_pos(*a, min_node);
		size = stack_size(*a);
		while (*a != min_node)
		{
			if (pos <= size / 2)
				ra(a, context);
			else
				rra(a, context);
		}
		pb(a, b, context);
	}
	sort_3(a, context);
	while (*b)
		pa(a, b, context);
}

void	sort_small(t_node **a, t_node **b, t_ctx *context)
{
	int	len;

	len = stack_size(*a);
	if (len <= 1 || is_sorted(*a))
		return ;
	if (len == 2)
		sa(a, context);
	else if (len == 3)
		sort_3(a, context);
	else
		sort4and5(a, b, context);
}
