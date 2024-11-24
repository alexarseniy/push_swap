/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:36:56 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/24 18:46:41 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

/*
 * Function: swap_stack
 * --------------------
 * This functions swaps the first two elements of stack pointed by 'top'. Top 
 * MUST point to the first element of the stack, otherwise the behavior is 
 * undefined.
 *
 * top: Pointer to the first element of the stack
 *
 * returns: No return as it works directly in the memmory.
 */
void	swap_stack(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;

	if (!top || !(*top) || !(*top)->next)
		return ;
	first = *top;
	second = first->next;
	first->prev = second;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	*top = second;
}

/*
 * Function: swap_two_stacks
 * -------------------------
 * This functions use the swap_stack function to swap the 2 first elements of
 * two different stacks that are received as directions. Both params MUST point
 * to the first element of each stack, otherwise the behavior is undefined.
 *
 * top_a: Pointer to the first element of the stack a
 * top_b: Pointer to the first element of the stack b
 *
 * returns: No return as it works directly in the memmory
 */
void	swap_both_stacks(t_stack **top_a, t_stack **top_b)
{
	if (!top_a || !top_b || !(*top_a) || !(*top_b))
		return ;
	if (*top_a && (*top_a)->next)
		swap_stack(top_a);
	if (*top_b && (*top_b)->next)
		swap_stack(top_b);
}

/*
 * Function: push_stack
 * ----------------
 * This fuction takes the first element of the stack 'src' and push it to the
 * top of the stack 'dest'. Both params must to point to the first element of
 * each stack, otherwise the behavior is undefined.
 *
 * top_dest: Pointer to the first element of the stack dest.
 * top_src: Pointer to the first element of the stack src.
 *
 * returns: No return as it works directly in the memmory.
 */
void	push_stack(t_stack **top_dest, t_stack **top_src)
{
	t_stack	*dest;
	t_stack	*src;

	if (!top_dest || !top_src || !(*top_src))
		return ;
	src = *top_src;
	dest = *top_dest;
	*top_src = src->next;
	if (src->next)
		src->next->prev = NULL;
	src->next = dest;
	if (dest)
		dest->prev = src;
	*top_dest = src;
}

/*
 * Function: rotate_stack
 * ----------------------
 * This function takes the first element of stack pointed by 'top' and places
 * it at the end of the stack, adjusting the pointers 'next' and 'prev'. The
 * pointer MUST point to the first element, otherwise the behavior is undefined
 *
 * top: pointer to the first element of the stack.
 *
 * returns: No return as it works directly in the memmory.
 */
void	rotate_stack(t_stack **top)
{
	t_stack	*first;
	t_stack	*last;

	if (!top || !*top || !(*top)->next)
		return ;
	first = *top;
	last = stack_last(first);
	*top = first->next;
	(*top)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

/*
 * Function: reverse_rotate_stack
 * ------------------------------
 * This functions taks the last element of the stack pointedd by 'top' and put
 * it at the begining of the stack. The pointer 'top' MUST point to the first
 * element of the stack, otherwise the behavior is undefined.
 *
 * top: Pointer to the first element of the stack.
 *
 * returns: No return as it works directly in the memmory.
 */
void	reverse_rotate_stack(t_stack **top)
{
	t_stack	*first;
	t_stack	*last;

	if (!top || !(*top) || !(*top)->next)
		return ;
	first = *top;
	last = stack_last(first);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*top = last;
}
