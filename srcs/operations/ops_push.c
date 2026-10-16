/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:36:52 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/01 23:36:52 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_node **a, t_node **b, t_ctx *context)
{
	t_node	*moved;

	if (!*b)
		return ;
	moved = *b;
	*b = moved->next;
	if (*b)
		(*b)->prev = NULL;
	moved->next = *a;
	moved->prev = NULL;
	if (*a)
		(*a)->prev = moved;
	*a = moved;
	log_op(OP_PA, context);
}

void	pb(t_node **a, t_node **b, t_ctx *context)
{
	t_node	*moved;

	if (!*a)
		return ;
	moved = *a;
	*a = moved->next;
	if (*a)
		(*a)->prev = NULL;
	moved->next = *b;
	moved->prev = NULL;
	if (*b)
		(*b)->prev = moved;
	*b = moved;
	log_op(OP_PB, context);
}
