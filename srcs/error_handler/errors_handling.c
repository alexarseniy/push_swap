/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:22:23 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/26 21:17:03 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "error_handler.h"
#include "libft.h"
#include <stdbool.h>

/*
 * Function: error_message
 * -----------------------
 * This functions print error message and return the error number defined in
 * the 'e_error' enum structure in the push_swap.h file
 *
 * error: recieve a constant number defined in enum e_errors structure.
 * 
 * returns: return the same error number.
 */
int	error_message(t_errors error) {
	ft_putstr_fd("Error\n", 2);
	return (error);
}

/*
 * Function: check_valid_input
 * ---------------------------
 * This functions validate the input for each number it receive as string, if
 * it is a valid number: Not NULL, not a void string, it's a number (positive
 * or negative) or it is an integer, specified by the subject. Otherwise,
 * it will close the program printing the "Error\n" message and exit with the 
 * error number.
 *
 * s_num: String that contain a chain of numbers or a '-' sign followed by a chain
 *      of numbers.
 * num: Same number transformed to integer
 * stack: Double linked list-based stack that will be checked for duplicates.
 *
 * return: true if it passed all the validations.
 */
int	check_valid_input(char *s_num, int num, t_stack *stack)
{
	if (!s_num)
		return (ERROR_NULL_NUM_STR);
	if (!*s_num)
		return (ERROR_VOID_NUM_STR);
	if (!is_number(s_num))
		return (ERROR_NOT_A_NUMBER);
	if (!is_integer(s_num))
		return (ERROR_NOT_AN_INTEGER);
	if (is_duplicated(num, stack))
		return (ERROR_DUP_NUM);
	return (OK);
}

/*
 * Function: is_duplicated
 * -----------------------
 * This functions check if the number already exist in the created stack. If
 * the stack doesn't exist, then it is the first element of it. If the number
 * already exists in the stack, the function will exit with the error code for
 * the duplicated numbers and print the error message.
 * 
 * num: The integer number.
 * stack: The double linked list-based stack that store the numbers.
 *
 * return: return false if it passed the validation.
 */
int is_duplicated(int num, t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack && stack->value != num)
		stack = stack->next;
	if (stack && stack->value == num)
		return (true);
	else
		return (false);
}

/*
 * Function: is_number
 * -------------------
 * Validate if the received string is a valid positive number (all chars are 
 * digits) or negative number ('-' followed by chain of digits).
 *
 * num: String that will be checked.
 *
 * returns: return true if it is a valid number or false if not.
 */
int	is_number(char *num)
{
	if (!num || !*num)
		return (false);
	if (*num == '-')
		num++;
	while (*num && ft_isdigit(*num))
		num++;
	if (!*num)
		return (true);
	else
		return (false);
}

/*
 * Function: is_integer
 * --------------------
 * Validade if the received string is a valid integer. It means that the number
 * will fall in the space of the int type data range. The string must be a
 * valid number (all digits or '-' followed by digits). Otherwise, the behavior
 * is undefined.
 *
 * num: String that contain a number.
 *
 * return: Return true or false depending if it is an integer or not.
 */
int is_integer(char *num)
{
	int	len;

	if (!num || !*num)
		return (false);
	len = ft_strlen(num);
	if (len > 10 && ft_isdigit(*num))
		return (false);
	if (len > 11)
		return (false);
	if (len == 11 && *num == '-')
		return (ft_strncmp(num, S_INT_MIN, 11) <= 0);
	if (len == 10)
		return (ft_strncmp(num, S_INT_MAX, 10) <= 0);
	else
		return (true);
}
