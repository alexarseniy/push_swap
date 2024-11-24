/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:50:42 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/24 20:29:51 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: main
 * --------------
 * Main function that starts all the program. It uses ENUM structure to handle
 * basic errors. Firstly, main function will initiate the double linked
 * list based stack and then will start the sorting algorithm. After sorting,
 * the stack will be cleared.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc != 2)
		return (error_message(ERROR_N_ARGS));
	stack = init_stack(argv[1]);
	if (!stack)
		return (error_message(ERROR_INIT_STACK));
	stack = push_swap(stack);
	if (!stack)
		return (error_message(ERROR_PUSH_SWAP));
	stack_clear(stack);
	return (OK);
}
