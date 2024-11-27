/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:23:18 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/26 21:05:30 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# define S_INT_MAX "2147483647"
# define S_INT_MIN "-2147483648"

/*
 * Typedef: t_errors
 * ----------------------
 * An enum e_errors structure that contains a constant values for error codes,
 * starting from 0 as OK.
 * 
 * ERROR_NULL_NUM_STR: The number passed as string is NULL
 * ERROR_VOID_NUM_STR: The number passed as string is a void string
 * ERROR_NOT_A_NUMBER: The number passed as string contains chars that are not
 *                     valid digits or symbol that is not '-' at the begining
 *                     of the string.
 * ERROR_NOT_AN_INTEGER: The number passed as string does not fall within int
 *                       range.
 * ERROR_DUP_NUM: The number casted to int already exist in the stack
 * ERROR_UPDATE_INDEX: There is an error while updating the index for the stack
 *                     nodes.
 * ERROR_NO_ARGS: There is no arguments.
 * ERROR_INIT_STACK: There is an error while initializing the stack
 * ERROR_PUSH_SWAP: There is an error while performing the sorting algorithm
 * ERROR_CREATE_NEW_NODE: There is an error while creating a new node. Usually
 *                        related with memmory issues (malloc failed).
 */
typedef enum e_errors
{
	OK = 0,
	ERROR_NULL_NUM_STR,
	ERROR_VOID_NUM_STR,
	ERROR_NOT_A_NUMBER,
	ERROR_NOT_AN_INTEGER,
	ERROR_DUP_NUM,
	ERROR_UPDATE_INDEX,
	ERROR_NO_ARGS,
	ERROR_INIT_STACK,
	ERROR_PUSH_SWAP,
	ERROR_CREATE_NEW_NODE
}	t_errors;

int		error_message(t_errors error);
int		check_valid_input(char *s_num, int num, t_stack *stack);
int 	is_duplicated(int num, t_stack *stack);
int		is_number(char *num);
int 	is_integer(char *num);
void	exit_and_free(t_stack *stack, t_errors error);

#endif
