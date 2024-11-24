/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:45:31 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/24 18:45:46 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

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
