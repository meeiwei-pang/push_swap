/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:34:25 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/01 12:05:40 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node **stack)
{
	int	index;
	int	pos;
	t_node	*current;
	t_node	*temp;

	temp = *stack;
	pos = 1;
	while (temp)
	{
		index = 0; //initialize index to 0 for each node
		current = *stack;
		while (current)
		{
			if (temp->value > current->value) //compare the value of the current node with all other nodes
				index++; //increment index if the current node's value is greater than the other node's value
			current = current->next;
		}
		temp->pos = pos++; //assign the position of the node in the stack
		temp->index = index; //assign the index of the node based on the number of nodes with smaller values
		temp = temp->next; //move to the next node in the stack
	}
}

float	disorder_check(t_node *stack)
{
	int	mistakes;
	int	total_pairs;
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
			if (current->index > next_node->index) //check if the current node's index is greater than the next node's index
				mistakes++; //each time the current node's index is greater than the next node's index, the pair counts as a mistake
			next_node = next_node->next;
		}
		current = current->next;
	}
	if (total_pairs == 0) //to avoid division by zero
		return (0.0f);
	return ((float)mistakes / (float)total_pairs); //the more mistakes you have, the closer the disorder is to 1. 
}

int	is_sorted(t_node *stack)
{
	if (!stack || !stack->next) //if stack is empty or has only one element, it is sorted
		return (1);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0); //if the current node's index is greater than the next node's index, the stack is not sorted
		stack = stack->next;
	}
	return (1); //if we reach here, the stack is sorted
}