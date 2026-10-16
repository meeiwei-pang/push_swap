/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:34:25 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/16 12:34:54 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	assign_index(t_node **stack)
{
	int		index;
	t_node	*current;
	t_node	*temp;

	temp = *stack;
	while (temp)
	{
		index = 0;
		current = *stack;
		while (current)
		{
			if (temp->value > current->value)
				index++;
			current = current->next;
		}
		temp->index = index;
		temp = temp->next;
	}
}

float	disorder_check(t_node *stack)
{
	int		mistakes;
	int		total_pairs;
	t_node	*current;
	t_node	*next_node;

	mistakes = 0;
	total_pairs = 0;
	current = stack;
	while (current)
	{
		next_node = current->next;
		while (next_node)
		{
			total_pairs++;
			if (current->index > next_node->index)
				mistakes++;
			next_node = next_node->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}

int	is_sorted(t_node *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}
