/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:05:01 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/09 18:43:22 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **stack, t_ctx *context)
{
	t_node	*max_node;

	if (!stack || !*stack)
		return;
	max_node = find_max(*stack);
	if (max_node == *stack) //if max_node is the 1st node
		ra(stack, context);
	else if (max_node == (*stack)->next) //if max_node is the 2nd node
		rra(stack, context);
	if ((*stack)->value > (*stack)->next->value) //compare 1st node and 2nd node one last time
		sa(stack, context);	                      
}

void	sort4and5(t_node **a, t_node **b, t_ctx *context)
{
	t_node	*min_node;
	int	pos;
	int	size;

	if (!a || !*a)
		return ;
	while (ft_lstsize(*a) > 3) //loop until stack a has 3 nodes
	{
		min_node = find_min(*a);
		pos = get_pos(*a, min_node);
		size = ft_lstsize;
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
	while (*b) //push nodes in b back to a 
		pa(a, b, context);
}

void	sort_small(t_node **a, t_node **b, t_ctx *context)
{
	int	len;

	len = ft_lstsize(*a);
	if (len <= 1 || is_sorted(*a))
		return ;
	if (len == 2)
		sa(a, context);
	else if (len == 3)
		sort_3(a, context);
	else
		sort4and5(a, b, context);
}