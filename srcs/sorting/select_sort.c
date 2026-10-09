/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:52:08 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/09 18:44:14 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(t_node **a, t_node **b, int size, t_ctx *context)
{
	if (is_sorted(*a))
		return ;
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
		sort_adaptive(a, b, context->disorder, context, size);
}
