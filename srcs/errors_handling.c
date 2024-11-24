/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:22:23 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/24 20:35:29 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error_handler.h"

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
int	error_message(enum e_errors error)
{
	ft_putstr_fd("Error\n");
	return (e);
}


