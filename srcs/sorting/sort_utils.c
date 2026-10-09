/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:42:54 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/08 18:42:54 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_node *stack is a plain ptr, we only read the list and never change it*/
static int	get_distance(t_node *stack, int target)
{
	int	distance;

	distance = 0;
	while (stack && stack->index != target)
	{
		distance++;
		stack = stack->next;
	}
	return (distance);
}

t_node	*find_max(t_node *stack)
{
	t_node	*max_node;

	if (!stack)
		return (0);
	max_node = stack;
	while (stack)
	{
		if (stack->value > max_node-> value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

t_node	*find_min(t_node *stack)
{
	t_node	*min_node;

	if (!stack)
		return (0);
	min_node = stack;
	while (stack)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

int	get_pos(t_node *stack, t_node *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	get_max_bits(int size)
{
	int	max_bits;
	int	max_num;

	if (size <= 1)
		return (0);
	max_bits = 0;
	max_num = size - 1;
	while ((max_num >> max_bits) > 0) // '>>' bitwise right shift operator
		max_bits++;
	return (max_bits);
}
