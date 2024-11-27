/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:40:48 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/27 18:41:21 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

/*
 * Typedef: t_stack
 * ----------------
 * Defines a structure representing a stack node in a double-linked.
 *
 * value: Integer value stored in the node.
 * index: Auxiliar integer value that store the final index position.
 * prev: pointer to the previus node in the stack.
 * next: pointer to the next node in the stack.
 */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/*
 * Function prototypes
 * -------------------
 * These functions performs operations on a double linked list-based stack.
 */
t_stack	*stack_new(int value);
t_stack *stack_last(t_stack *stack);
void	stack_add_last(t_stack **dest, t_stack *new);
int		stack_size(t_stack *stack);
void	*stack_clear(t_stack **top);
void	swap_stack(t_stack **top);
void	swap_both_stacks(t_stack **top_a, t_stack **top_b);
void	push_stack(t_stack **top_dest, t_stack **top_src);
void	rotate_stack(t_stack **top);
void	rotate_both_stacks(t_stack **top_a, t_stack **top_b);
void	reverse_rotate_stack(t_stack **top);
void	reverse_rotate_both_stacks(t_stack **top_a, t_stack **top_b);
void	print_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif
