/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 08:27:39 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/01 14:13:46 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		context->count[i] = 0; //initialize the count of each operation to 0
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
	init_ctx(&context); //initialize configuration and stats settings 
	if (!init_stack(argc, argv, &a, &context)) //if failure in parsing
	{
		free_stack(&a);
		write(2, "Error\n", 6); //write to fd stderr
		return (1); //exits program with failure status
	}
	if (!a) //if parsing is a success but a is empty (program run without any arg)
		return (0); //not considered an error, just exit program
	assign_index(&a); //replace each value with its sorted rank (0, 1, 2 ...)
	context.disorder = disorder_check(a); //check percentage of disorder
	select_sort(&a, &b, ft_lstsize(a), &context); //determine which algorithm to use and execute it
	if (context.bench == 1)
		print_bench_stats(&context); //print benchmark stats if requested
	free_stack(&a);
	free_stack(&b); //stack b should be empty at the end but we can free it just in case
	return (0);
}
