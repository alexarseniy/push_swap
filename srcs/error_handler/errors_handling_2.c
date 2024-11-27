/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:29:12 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/26 21:12:02 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "error_handler.h"
#include <stdlib.h>
#include "libft.h"

/*
 * Function: exit_and_free
 * -----------------------
 * Free the alocated memory in stack and exit the program with the error number
 *
 * stack: the double linked list-based stack that must to be freed.
 * error: error number that will indicate where is the error.
 * 
 * return: No return
 */
void	exit_and_free(t_stack *stack, t_errors error)
{
	stack_clear(&stack);
	ft_putstr_fd("Error\n", 2);
	exit(error);
}
