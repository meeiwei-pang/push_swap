/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 08:27:39 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/16 12:28:12 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_ctx(t_ctx *context)
{
	int	i;

	context->flag = FLAG_UNKNOWN;
	context->strategy = STRAT_UNKNOWN;
	context->bench = 0;
	context->disorder = 0.0f;
	context->print = 1;
	context->total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		context->count[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_ctx	context;

	a = NULL;
	b = NULL;
	init_ctx(&context);
	if (!init_stack(argc, argv, &a, &context))
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!a)
		return (0);
	assign_index(&a);
	context.disorder = disorder_check(a);
	select_sort(&a, &b, stack_size(a), &context);
	if (context.bench == 1)
		print_bench_stats(&context);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
