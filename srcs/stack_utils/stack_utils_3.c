/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:45:31 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/07 16:48:22 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "stdio.h"
#include <stdbool.h>

/*
 * Function: reverse_rotate_both_stacks
 * ------------------------------------
 * This function takes the last element of the both stackspointed by 'top_a' and
 * 'top_b' and put them at the begining of respective stacks. The pointers MUST
 * point to the first element of each stack, otherwise the behavior is
 * undefined
 *
 * top_a: Pointer to the first element of the stack a.
 * top_b: Pointer to the first element of the stack b.
 *
 * returns: No return as it works directly in the memmory.
 */
void	reverse_rotate_both_stacks(t_stack **top_a, t_stack **top_b)
{
	if (!top_a || !top_b || !(*top_a) || !(*top_b))
		return ;
	if (*top_a && (*top_a)->next)
		reverse_rotate_stack(top_a);
	if (*top_b && (*top_b)->next)
		reverse_rotate_stack(top_b);
}

/*
 * Function: rotate_both_stacks
 * ------------------------------------
 * This function takes the first element of the both stackspointed by 'top_a'
 * and 'top_b' and put them at the end of respective stacks. The pointers
 * MUST point to the first element of each stack, otherwise the behavior is
 * undefined
 *
 * top_a: Pointer to the first element of the stack a.
 * top_b: Pointer to the first element of the stack b.
 *
 * returns: No return as it works directly in the memmory.
 */
void	rotate_both_stacks(t_stack **top_a, t_stack **top_b)
{
	if (!top_a || !top_b || !(*top_a) || !(*top_b))
		return ;
	if (*top_a && (*top_a)->next)
		rotate_stack(top_a);
	if (*top_b && (*top_b)->next)
		rotate_stack(top_b);
}
/*
 * Function: print_stack
 * ---------------------
 * Print the values and indexes of all stack nodes.
 *
 * stack: A double linked list-based stack that will be printed
 */
void	print_stack(t_stack *stack)
{
	int	i;

	if (!stack)
		printf("(Null)\n");
	else
	{
		i = 0;
		while (stack)
		{
			printf("Element [%i]:\n\tValue: %d\n", i, stack->value);
			printf("\tIndex: %d\n", stack->index);
			stack = stack->next;
			i++;
		}
	}
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack)
	{
		if (stack->next && stack->index > stack->next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*stack_first(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack=stack->prev;
	return (stack);
}
