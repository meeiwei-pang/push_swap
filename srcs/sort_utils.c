/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:42:54 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/08 18:42:54 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_node *stack is a plain ptr, we only read the list and never change it*/
static int	get_distance(t_node *stack, int target)
{
	int	distance;

	distance = 0;
	while (stack && stack->index != target)
	{
		distance++;
		stack = stack->next;
	}
	return (distance);
}