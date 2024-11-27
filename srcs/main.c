/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:50:42 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/26 22:12:06 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"

/*
 * Function: set_update_indexes
 * ----------------------------
 * This function go through the stack and check if the number is bigger or lower
 * than the number setted in each node. If the number is bigger than the node's
 * one, then grow the new index by 1. Otherwise, update the node's index by +1
 *
 * num: number to be checked.
 * stack: the double linked list-based stack that will be checked.
 *
 * return: return the new index value for the new node added.
 */
int	set_update_indexes(int num, t_stack *stack)
{
	int	index;

	if (!stack)
		return (-1);
	index = 0;
	while (stack)
	{
		if (num > stack->value)
			index++;
		if (num < stack->value)
			stack->index++;
		stack = stack->next;
	}
	return (index);
}

/*
 * Function: init_stack
 * --------------------
 * This function launch the checks to validade each number from the 'num_list'
 * to validade the numbers, and if it pass it, the number will be added to the
 * stack, and then, it will update the final indexes (final positions).
 *
 * num_list: array of strings of the numbers that are given as arguments to the
 *           program, that are needed to validate and add to the stack.
 *
 * return: return the created stack or NULL if the num_list is NULL or exit
 *         the program if there any error during the checks or memory reserve
 *         with malloc.
 */
t_stack	*init_stack(char **num_list)
{
	int			num;
	t_errors	error;
	t_stack		*stack;

	if (!num_list)
		return (NULL);
	stack = NULL;
	while (*num_list)
	{
		num = ft_atoi(*num_list);
		error = check_valid_input(*num_list, num, stack);
		if (error != OK)
			exit_and_free(stack, error);
		stack_add_last(&stack, stack_new(num));
		if (!stack)
			exit_and_free(stack, ERROR_CREATE_NEW_NODE);
		stack_last(stack)->index = set_update_indexes(num, stack);
		if (stack->index == -1)
			exit_and_free(stack, ERROR_UPDATE_INDEX);
		num_list++;
	}
	return (stack);
}

/*
 * Function: main
 * --------------
 * Main function that starts all the program. It uses ENUM structure to handle
 * basic errors. Firstly, main function will initiate the double linked
 * list based stack and then will start the sorting algorithm. After sorting,
 * the stack will be cleared.
 *
 * argc: Number of arguments that receive the program.
 * argv: Array of arguments that are passed to the program.
 *
 * return: Return OK from the enum e_error structure (has 0 as value).
 */
int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (error_message(ERROR_NO_ARGS));
	stack = init_stack(argv + 1);
	if (!stack)
		return (error_message(ERROR_INIT_STACK));
	stack = push_swap(stack);
	if (!stack)
		return (error_message(ERROR_PUSH_SWAP));
	print_stack(stack);
	stack_clear(&stack);
	return (OK);
}
