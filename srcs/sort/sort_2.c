/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:21:23 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/27 18:54:19 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	select_move(t_stack **a, t_stack **b, t_move m)
{
	if (m == SA)
		swap_stack(a);
	else if (m == SB)
		swap_stack(b);
	else if (m == SS)
		swap_both_stacks(a, b);
	else if (m == PA)
		push_stack(a, b);
	else if (m == PB)
		push_stack(b, a);
	else if (m == RA)
		rotate_stack(a);
	else if (m == RB)
		rotate_stack(b);
	else if (m == RR)
		rotate_both_stacks(a, b);
	else if (m == RRA)
		reverse_rotate_stack(a);
	else if (m == RRB)
		reverse_rotate_stack(b);
	else if (m == RRR)
		reverse_rotate_both_stacks(a, b);
	print_move(m);
}

void	print_move(t_move m)
{
	if (m == SA)
		ft_putstr_fd("SA\n", 0);
	else if (m == SB)
		ft_putstr_fd("SB\n", 0);
	else if (m == SS)
		ft_putstr_fd("SS\n", 0);
	else if (m == PA)
		ft_putstr_fd("PA\n", 0);
	else if (m == PB)
		ft_putstr_fd("PB\n", 0);
	else if (m == RA)
		ft_putstr_fd("RA\n", 0);
	else if (m == RB)
		ft_putstr_fd("RB\n", 0);
	else if (m == RR)
		ft_putstr_fd("RR\n", 0);
	else if (m == RRA)
		ft_putstr_fd("RRA\n", 0);
	else if (m == RRB)
		ft_putstr_fd("RRB\n", 0);
	else if (m == RRR)
		ft_putstr_fd("RRR\n", 0);
}
