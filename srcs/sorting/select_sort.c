/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:52:08 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/01 13:45:41 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(t_node **a, t_node **b, int size, t_ctx *context)
{
	if (size < 2 || is_sorted(*a)) //if the stack is already sorted or only has 1 element, no need to sort
	{
		if (context->strategy == STRAT_UNKNOWN)
			context->strategy = STRAT_SMALL; //if no strategy was set, set it to small
		return ;
	}
	if (context->flag == FLAG_SIMPLE)
	{
		context->strategy = STRAT_SIMPLE;
		sort_simple(a, b, context);
	}
	else if (context->flag == FLAG_MEDIUM)
	{
		context->strategy = STRAT_MEDIUM;
		sort_medium(a, b, context);
	}
	else if (context->flag == FLAG_COMPLEX)
	{
		context->strategy = STRAT_COMPLEX;
		sort_complex(a, b, context);
	}
	else
		sort_adaptive(a, b, context->disorder, context);
}

