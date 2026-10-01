/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibishak <ibishak@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:38:32 by ibishak           #+#    #+#             */
/*   Updated: 2026/10/01 13:48:06 by ibishak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*Standard Library*/
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

# define FLAG_UNKNOWN 0
# define FLAG_SIMPLE 1
# define FLAG_MEDIUM 2
# define FLAG_COMPLEX 3
# define FLAG_ADAPTIVE 4

# define STRAT_UNKNOWN 0
# define STRAT_SMALL 1
# define STRAT_SIMPLE 2
# define STRAT_MEDIUM 3
# define STRAT_COMPLEX 4

/*Data Structure*/
typedef struct s_node
{
	int		value;	//number
	int		index;	//index assigned in stack_analysis
	int		pos;
	struct s_node	*next; //doubly linked list
	struct s_node	*prev;
}	t_node;

typedef struct s_ctx //context: configuration and statistics for the program
{
	int	flag;		//which strategy the user choose
	int	strategy;	//which class the input falls into
	int	bench;		//whether benchmark is to be printed
	float	disorder;	//how unsorted the input is
	int	print;		//whether to print the operations (sa, pb, ra...)
	int	count[OP_COUNT]; //how many times each operation was used
	int	total;		//total number of operations
}	t_ctx;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

#endif