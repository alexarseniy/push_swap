/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:03:13 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/04 23:04:39 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

static int	update_pos_w_stack(t_stack *a, t_stack *b, t_move move)
{
	int	i;

	if (!a && !b)
		return (-1);
	if (move == PA)
		a->w_stack = STACK_A;
	if (move == PB)
		b->w_stack = STACK_B;
	i = 0;
	while (a)
	{
		a->r_pos = i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->r_pos = i++;
		b = b->next;
	}
	return (0);
}

static void	print_move(t_move move)
{
	static const char	*s_move[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};

	ft_printf("%s\n", s_move[move]);
}

static int	execute_move(t_stack **a, t_stack **b, t_move move)
{
	if (move == SA)
		return (stack_swap(a));
	else if (move == SB)
		return (stack_swap(b));
	else if (move == SS)
		return (stack_sswap(a, b));
	else if (move == PA)
		return (stack_push(b, a));
	else if (move == PB)
		return (stack_push(a, b));
	else if (move == RA)
		return (stack_rotate(a));
	else if (move == RB)
		return (stack_rotate(b));
	else if (move == RR)
		return (stack_rrotate(a, b));
	else if (move == RRA)
		return (stack_rev_rotate(a));
	else if (move == RRB)
		return (stack_rev_rotate(b));
	else
		return (stack_rev_rrotate(a, b));
}

int	stack_move(t_stack **a, t_stack **b, t_move move)
{
	int	check;

	check = execute_move(a, b, move);
	if (!BONUS && !check)
		print_move(move);
	update_pos_w_stack(*a, *b, move);
	return (check);
}
