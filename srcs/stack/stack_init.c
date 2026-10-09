/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:37:39 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/09 15:42:37 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flag_detector(char *s, t_ctx *context)
{
	if (ft_strncmp(s, "--bench", 8) == 0) //check if the argument is the flag "--bench"
	{
		context->bench = 1; //set the bench flag in the t_ctx struct to 1
		return (1);
	}
	if (ft_strncmp(s, "--simple", 9) == 0 
		&& (context->flag == 1 || context->flag == 0)) //
		context->flag = FLAG_SIMPLE;
	else if (ft_strncmp(s, "--medium", 9) == 0 
		&& (context->flag == 2 || context->flag == 0)) //
		context->flag = FLAG_MEDIUM;
	else if (ft_strncmp(s, "--complex", 10) == 0 
		&& (context->flag == 3 || context->flag == 0)) //
		context->flag = FLAG_COMPLEX;	
	else if (ft_strncmp(s, "--adaptive", 11) == 0
		&& (context->flag == 4 || context->flag == 0))
		context->flag = FLAG_ADAPTIVE;
	else
		return (0); //return 0 if the argument is not a flag
	return (1); //return 1 if the argument is a flag
}

int	validate_arg(char *arg, t_node **a, t_ctx *context)
{
	t_node	*new_node;
	int	value;

	if (flag_detector(arg, context)) //check if arg is a flag
		return (1);
	if (!ft_atol(arg, &value) || is_duplicate(*a, value)) //check if arg is a valid integer and not duplicate
		return (0);
	new_node = ft_lstnew(value); //create a new node with the value
	if (!new_node) //if malloc fails, quit
		return (0);
	ft_lstadd_back(a, new_node); //add the new node to the end of stack
	return (1);
}

int	process_arg(char *arg, t_node **a, t_ctx *context)
{
	char	**split;
	int	i;

	split = ft_split(arg, ' ');
	if (!split) //if malloc fails, quit
		return (0);
	if (!split[0]) //if arg is empty string, free and then quit
		return (free_split(split), 0);
	i = 0;
	while (split[i])
	{
		if (!validate_arg(split[i], a, context)) //check for flags and validate each number in the split array
			return (free_split(split), 0);
		i++;
	}
	return (free_split(split), 1); //the numbers are transferred to stack a in validate_arg function, so we can free the split array
}

int	init_stack(int argc, char **argv, t_node **a, t_ctx *context)
{
	int	i;

	i = 1; // argv[0]=program name, so we start with argv[1]
	while (i < argc)
	{
		if (!process_arg(argv[i], a, context)) //process each argument, which may contain multiple numbers separated by spaces
			return (0);
		i++;
	}
	return (1);
}