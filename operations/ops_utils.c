/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeei-we <pmeei-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 23:13:56 by pmeei-we          #+#    #+#             */
/*   Updated: 2026/10/01 23:13:56 by pmeei-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*record operation, bump the total, print its name, use the same logic*/
void	log_op(t_op op, t_ctx *context)
{
	static const char	*op_names[] = {
		"sa", "sb", "ss",
		"pa", "pb",
		"ra", "rb", "rr",
		"rra", "rrb", "rrr"
	};

	context->count[op]++;
	context->total++;
	if (context->print) /*if true,output the opr by a newline*/
		ft_putendl_fd((char *)op_names[op], 1); /*1=stdout*/
}
