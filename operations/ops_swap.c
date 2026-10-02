/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:28:57 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/01 23:28:57 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ptr relinking, swap first 2 nodes only*/
static void	swap_node(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
}

/*swap the first 2 elements at the top of stack a <2*/
void	sa(t_node **a, t_ctx *context)
{
	if (!*a || !(*a)->next) /*check if stack is empty or only one node*/
		return ;
	swap_node(a);
	log_op(OP_SA, context);
}

/*swap the first 2 elements at the top of stack b <2*/
void	sb(t_node **b, t_ctx *context)
{
	if (!*b || !(*b)->next)
		return ;
	swap_node(b);
	log_op(OP_SB, context);
}

/*if both A and B have 2++ nodes,both swap,print "ss"
either also "ss"*, ss swap at least 2 element*/
void	ss(t_node **a, t_node **b, t_ctx *context)
{
	int	moved;

	moved = 0;
	if (*a && (*a)->next)
	{
		swap_node(a);
		moved = 1;
	}
	if (*b && (*b)->next)
	{
		swap_node(b);
		moved = 1;
	}
	if (moved)
		log_op(OP_SS, context);
}
