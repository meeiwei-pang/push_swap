/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:43:44 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/01 23:43:44 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_node(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	last = *stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_node **a, t_ctx *context)
{
	if (!*a || !(*a)->next)
		return ;
	reverse_rotate_node(a);
	log_op(OP_RRA, context);
}

void	rrb(t_node **b, t_ctx *context)
{
	if (!*b || !(*b)->next)
		return ;
	reverse_rotate_node(b);
	log_op(OP_RRB, context);
}

void	rrr(t_node **a, t_node **b, t_ctx *context)
{
	int	moved;

	moved = 0;
	if (*a && (*a)->next)
	{
		reverse_rotate_node(a);
		moved = 1;
	}
	if (*b && (*b)->next)
	{
		reverse_rotate_node(b);
		moved = 1;
	}
	if (moved)
		log_op(OP_RRR, context);
}