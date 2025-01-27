/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:32:35 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/08 10:03:02 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack_utils.h"
# include "error_handler.h"
# include <stdlib.h>

typedef enum e_move
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_move;

t_stack	*init_stack(char **num_list);
void	exit_and_free(t_stack *stack, t_errors error);
int		set_update_indexes(int num, t_stack *stack);
t_stack	*push_swap(t_stack *stack);
int		main(int argc, char **argv);
t_stack	*small_sort(t_stack *a);
t_stack	*mid_sort(t_stack *a, t_stack *b);
t_stack *big_sort(t_stack *a, t_stack *b);
void	execute_move(t_stack **a, t_stack **b, t_move m);
void	print_move(t_move m);
t_move	select_next_move(t_stack *a, t_stack *b);
t_move	select_rotate(t_stack *a, t_stack *b);
int		b_smalest(t_stack *a, t_stack *b);

#endif
