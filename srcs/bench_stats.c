/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:36:53 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/08 18:36:53 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*complexity(int strategy)
{
	if (strategy == STRAT_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRAT_MEDIUM)
		return ("O(n√n)");
	if (strategy == STRAT_COMPLEX)
		return ("O(n log n)");
	return ("O(1)");
}

static void	print_percent(float disorder)
{
	int	scaled;

	scaled = (int)(disorder * 10000 + 0.5f);
	ft_putnbr_fd(scaled / 100, 2);
	ft_putchar_fd('.', 2);
	if (scaled % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(scaled % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_ctx *context)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (context->flag == FLAG_SIMPLE)
		ft_putstr_fd("Simple", 2);
	else if (context->flag == FLAG_MEDIUM)
		ft_putstr_fd("Medium", 2);
	else if (context->flag == FLAG_COMPLEX)
		ft_putstr_fd("Complex", 2);
	else
		ft_putstr_fd("Adaptive", 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity(context->strategy), 2);
	ft_putchar_fd('\n', 2);
}

static void	print_counts(t_ctx *context, int first, int last)
{
	ft_putstr_fd("[bench]", 2);
	while (first <= last)
	{
		ft_putchar_fd(' ', 2);
		ft_putstr_fd(op_name(first), 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(context->count[first], 2);
		first++;
	}
	ft_putchar_fd('\n', 2);
}

void	print_bench_stats(t_ctx *context)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(context->disorder);
	print_strategy(context);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(context->total, 2);
	ft_putchar_fd('\n', 2);
	print_counts(context, OP_SA, OP_PB);
	print_counts(context, OP_RA, OP_RRR);
}