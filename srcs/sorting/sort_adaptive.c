/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:02:14 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/01 14:02:57 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_node **a, t_node **b, float disorder, t_ctx *context)
{
	if (ft_lstsize(*a) <= 5)
	{
		context->strategy = STRAT_SMALL;
		sort_small(a, b, context);
	}
	else if (disorder < 0.2f)
	{
		context->strategy = STRAT_SIMPLE;
		sort_simple(a, b, context);
	}
	else if (disorder < 0.5f && disorder >= 0.2f)
	{
		context->strategy = STRAT_MEDIUM;
		sort_medium(a, b, context);
	}
	else
	{
		context->strategy = STRAT_COMPLEX;
		sort_complex(a, b, context);
	}
}