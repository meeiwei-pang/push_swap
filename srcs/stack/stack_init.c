/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 13:11:06 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/16 13:11:09 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	flag_detector(char *s, t_ctx *context)
{
	if (ft_strncmp(s, "--bench", 8) == 0)
	{
		context->bench = 1;
		return (1);
	}
	if (ft_strncmp(s, "--simple", 9) == 0
		&& (context->flag == 1 || context->flag == 0))
		context->flag = FLAG_SIMPLE;
	else if (ft_strncmp(s, "--medium", 9) == 0
		&& (context->flag == 2 || context->flag == 0))
		context->flag = FLAG_MEDIUM;
	else if (ft_strncmp(s, "--complex", 10) == 0
		&& (context->flag == 3 || context->flag == 0))
		context->flag = FLAG_COMPLEX;
	else if (ft_strncmp(s, "--adaptive", 11) == 0
		&& (context->flag == 4 || context->flag == 0))
		context->flag = FLAG_ADAPTIVE;
	else
		return (0);
	return (1);
}

int	validate_arg(char *arg, t_node **a, t_ctx *context)
{
	t_node	*new_node;
	int		value;

	if (flag_detector(arg, context))
		return (1);
	if (!ft_atol(arg, &value) || is_duplicate(*a, value))
		return (0);
	new_node = stack_new(value);
	if (!new_node)
		return (0);
	add_back(a, new_node);
	return (1);
}

int	process_arg(char *arg, t_node **a, t_ctx *context)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	if (!split[0])
		return (free_split(split), 0);
	i = 0;
	while (split[i])
	{
		if (!validate_arg(split[i], a, context))
			return (free_split(split), 0);
		i++;
	}
	return (free_split(split), 1);
}

int	init_stack(int argc, char **argv, t_node **a, t_ctx *context)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!process_arg(argv[i], a, context))
			return (0);
		i++;
	}
	return (1);
}
