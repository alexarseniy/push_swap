/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:32:35 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/26 19:34:16 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack_utils.h"
# include "error_handler.h"

t_stack	*init_stack(char **num_list);
void	exit_and_free(t_stack *stack, t_errors error);
int		set_update_indexes(int num, t_stack *stack);
t_stack	*push_swap(t_stack *stack);
int		main(int argc, char **argv);

#endif
