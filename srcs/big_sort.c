/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:33:19 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/08 05:25:57 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_sort(t_stack **a, t_stack **b)
{
	int		median;
	t_stack	*node;

	while (*b)
	{
		median = stack_size(*b) / 2;
		calculate_merge_cost(*a, *b, median);
		node = min_cost(*b);
		if (node->cost == 0)
		{
			stack_move(a, b, PA);
			continue ;
		}
		stack_move(a, b, node->move);
		if (node->move == RB)
			stack_move(a, b, RRA);
		else if (node->move == RRB)
			stack_move(a, b, RA);
	}
	return (0);
}

static int	recursive_split(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	min;

	if (size <= 3)
		return (0);
	min = stack_min(*a)->f_pos;
	pivot = (stack_max(*a)->f_pos - min) / 3;
	while (*a && (min + pivot * 2 + 1) >= stack_min(*a)->f_pos
		&& stack_size(*a) > 3)
	{
		if ((*a)->f_pos <= min + pivot)
		{
			stack_move(a, b, PB);
			stack_move(a, b, RB);
		}
		else if ((*a)->f_pos > (min + pivot)
			&& (*a)->f_pos <= (min + pivot * 2 + 1))
			stack_move(a, b, PB);
		else if ((*a)->f_pos > (min + pivot * 2 + 1))
			stack_move(a, b, RA);
	}
	recursive_split(a, b, stack_size(*a));
	return (0);
}

int	big_sort(t_stack **a, t_stack **b)
{
	recursive_split(a, b, stack_size(*a));
	if (!(*a)->next)
		return (0);
	else if (stack_size(*a) == 2 && !is_sorted(*a))
		stack_move(a, b, SA);
	else
		sort_3(a, b);
	merge_sort(a, b);
	while (!is_sorted(*a))
	{
		if (stack_min(*a)->r_pos > (stack_size(*a) / 2))
			stack_move(a, b, RRA);
		else
			stack_move(a, b, RA);
	}
	return (0);
}
