/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:44:35 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/06 20:01:43 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

# ifndef BONUS
#  define BONUS 0
# endif

typedef enum e_move
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_move;

/*
 * enum e_w_stack represent in which stack actualy the node stored.
 *
 * STACK_A: the node actually is in stack a
 * STACK_B: The node actually is in stack B
 */
typedef enum e_w_stack
{
	STACK_A,
	STACK_B
} t_w_stack;

/*
 *	Struct s_stack is a struct that implements a double linked list-based stack.
 *	This struct will have the following information.
 *
 *	-> value: integer type value that will store the actual value
 *	-> f_pos: final position. The position where it has to be after the sort in
 *			  stack a.
 *	-> r_pos: real position. The actual position in the stack where is stored.
 *	-> w_stack: wich stack where the node is stored.
 *	-> cost: The cost of bring the node to the top of the stack.
 *	-> *next: pointer to the next node
 *	-> *prev: pointer to the previous node
 */
typedef struct s_stack
{
	int				value;
	int				f_pos;
	int 			r_pos;
	t_w_stack		w_stack;
	int				cost;
	t_move			move;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*
 * Prototype functions to initialize stack
 */
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *node);
t_stack	*stack_first(t_stack *node);
int		stack_add_last(t_stack **node, t_stack *new);
int 	stack_size(t_stack *node);
void	stack_print(t_stack *node);
void	stack_free(t_stack *node);
int		init_stack(t_stack **stack, int argc, char **argv);
int		stack_move(t_stack **a, t_stack **b, t_move move);
int		stack_push(t_stack **src, t_stack **dst);
int		stack_rotate(t_stack **src);
int		stack_rev_rotate(t_stack **src);
int		stack_swap(t_stack **src);
int		stack_sswap(t_stack **a, t_stack **b);
int		stack_rrotate(t_stack **a, t_stack **b);
int		stack_rev_rrotate(t_stack **a, t_stack **b);
bool	is_sorted(t_stack *a);

#endif
