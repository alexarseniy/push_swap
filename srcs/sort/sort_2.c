/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:21:23 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/08 12:28:38 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

/*
 * Function: execute_move
 * ----------------------
 * Function that execute a movement on each stack depending on the value of 'm'
 * Once the movement is executed, then it will print the same movement through
 * the function print_move. The function has no checks for each stack. This
 * checks must to be done outside of this function. This means that the movement
 * cannot be executed on each stack, the behavior is undefined.
 *
 * t_stack **a: A pointer to the first node of the stack a
 * t_stack **b: A pointer to the first node of the stack b
 * t_move m: The typedef of enum e_move that store the movement that will be
 *           executed
 *
 * returns: No return.
 */
void	execute_move(t_stack **a, t_stack **b, t_move m)
{
	if (m == SA)
		swap_stack(a);
	else if (m == SB)
		swap_stack(b);
	else if (m == SS)
		swap_both_stacks(a, b);
	else if (m == PA)
		push_stack(a, b);
	else if (m == PB)
		push_stack(b, a);
	else if (m == RA)
		rotate_stack(a);
	else if (m == RB)
		rotate_stack(b);
	else if (m == RR)
		rotate_both_stacks(a, b);
	else if (m == RRA)
		reverse_rotate_stack(a);
	else if (m == RRB)
		reverse_rotate_stack(b);
	else if (m == RRR)
		reverse_rotate_both_stacks(a, b);
	print_move(m);
}

/*
 * Function: print_move
 * --------------------
 * Function that prints the movement on the stack A or B that is executed.
 *
 * t_move m: The typedef of enum e_move that store the movement that is executed
 *
 * return: No return.
 */
void	print_move(t_move m)
{
	if (m == SA)
		printf("SA\n");
	else if (m == SB)
		printf("SB\n");
	else if (m == SS)
		printf("SS\n");
	else if (m == PA)
		printf("PA\n");
	else if (m == PB)
		printf("PB\n");
	else if (m == RA)
		printf("RA\n");
	else if (m == RB)
		printf("RB\n");
	else if (m == RR)
		printf("RR\n");
	else if (m == RRA)
		printf("RRA\n");
	else if (m == RRB)
		printf("RRB\n");
	else if (m == RRR)
		printf("RRR\n");
}

/*
 * Function: select_next_move
 * --------------------------
 * Function that based on the state of each stack, will return the best movement
 * that can be executed.
 *
 * t_stack *a: The first node of the stack a
 * t_stack *b: The first node of the stack b
 *
 * return: return a t_move value.
 */
t_move	select_next_move(t_stack *a, t_stack *b)
{
	if (b && b->next && b->index < b->next->index)
		return (SB);
	if (b && (b->index > stack_last(a)->index))
		return (PA);
	if (a->index == stack_last(a)->index + 1)
		return (RRA);
	if (a->index == stack_last(a)->index - 1)
		return (RA);
	if (a->index > a->next->index)
		return (SA);
	if (b && b_smalest(a, b))
		return (PA);
	return (select_rotate(a, b));
}

int	b_smalest(t_stack *a, t_stack *b)
{
	while (a && b && a->index > b->index)
		a = a->next;
	if (!a)
		return (1);
	return (0);
}

t_move select_rotate(t_stack *a, t_stack *b)
{
	float	mid_a;
	float	i;

	mid_a = stack_size(a) / 2;
	i = 0;
	while (a && b && (b->index > a->index || b->index == a->index + 1))
	{
		a = a->next;
		i++;
	}
	if (a && (i > mid_a))
		return (RRA);
	while (a && !b && a->next && a->index == a->next->index + 1)
	{
		a = a->next;
		i++;
	}
	if (a && i > mid_a)
		return (RRA);
	return (RA);
}
