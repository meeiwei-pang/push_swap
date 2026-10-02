/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:38:07 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/01 23:38:07 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_node(t_node **stack)
{
	t_node	*old_top;
	t_node	*last;

	old_top = *stack;
	*stack = old_top->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = old_top;
	old_top->prev = last;
	old_top->next = NULL;
}

void	ra(t_node **a, t_ctx *context)
{
	if (!*a || !(*a)->next)
		return ;
	rotate_node(a);
	log_op(OP_RA, context);
}

void	rb(t_node **b, t_ctx *context)
{
	if (!*b || !(*b)->next)
		return ;
	rotate_node(b);
	log_op(OP_RB, context);
}

void	rr(t_node **a, t_node **b, t_ctx *context)
{
	int	moved;

	moved = 0;
	if (*a && (*a)->next)
	{
		rotate_node(a);
		moved = 1;
	}
	if (*b && (*b)->next)
	{
		rotate_node(b);
		moved = 1;
	}
	if (moved)
		log_op(OP_RR, context);
}