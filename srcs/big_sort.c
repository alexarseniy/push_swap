/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:33:19 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/09 01:03:36 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	merge_sort(t_stack **a, t_stack **b, int pivot_min, int pivot_max)
{
	int		median;
	t_stack	*node;

	while (*b && stack_max(*b)->f_pos >= pivot_min)
	{
		median = (stack_size(*b)) / 2;
		calculate_merge_cost(*a, *b, median, stack_size(*b));
		node = min_cost(*b, pivot_min, pivot_max);
		if (!node)
			return (0);
		if (node->cost == 0)
		{
			stack_move(a, b, PA);
			continue ;
		}
		stack_move(a, b, node->move);
	}
	return (0);
}

static int	recursive_split(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	min;

	if (size <= 3)
		return (sort_3(a, b));
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
	merge_sort(a, b, min + pivot + 1, min + pivot * 2 + 1);
	merge_sort(a, b, min, min + pivot);
	return (0);
}

int	big_sort(t_stack **a, t_stack **b)
{
	recursive_split(a, b, stack_size(*a));
	while (!is_sorted(*a))
	{
		if (stack_min(*a)->r_pos > (stack_size(*a) / 2))
			stack_move(a, b, RRA);
		else
			stack_move(a, b, RA);
	}
	return (0);
}
