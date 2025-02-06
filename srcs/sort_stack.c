/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:47:35 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/06 20:01:24 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_min(t_stack *s)
{
	t_stack	*result;

	if (!s)
		return (NULL);
	if (stack_size(s) == 1)
		return (s);
	result = s;
	while (s)
	{
		if (s->f_pos < result->f_pos)
			result = s;
		s = s->next;
	}
	return (result);
}

t_stack	*stack_max(t_stack *s)
{
	t_stack	*result;

	if (!s)
		return (NULL);
	if (stack_size(s) == 1)
		return (s);
	result = s;
	while (s)
	{
		if (s->f_pos > result->f_pos)
			result = s;
		s = s->next;
	}
	return (result);
}

static int	sort_3(t_stack **a, t_stack **b)
{
	t_stack	*max;

	if (!a)
		return (-1);
	max = stack_max(*a);
	if (max->r_pos == 0 && (*a)->next->f_pos < (*a)->next->next->f_pos)
		stack_move(a, b, RA);
	else if (max->r_pos == 0 && (*a)->next->f_pos > (*a)->next->next->f_pos)
	{
		stack_move(a, b, RA);
		stack_move(a, b, SA);
	}
	else if (max->r_pos == 1 && (*a)->f_pos < (*a)->next->next->f_pos)
	{
		stack_move(a, b, RRA);
		stack_move(a, b, SA);
	}
	else if (max->r_pos == 1 && (*a)->f_pos > (*a)->next->next->f_pos)
		stack_move(a, b, RRA);
	else if (max->r_pos == 2 && (*a)->f_pos > (*a)->next->f_pos)
		stack_move(a, b, SA);
	return (0);
}


static int	sort_4(t_stack **a, t_stack **b)
{
	t_stack *max;

	if (!a || !b)
		return (-1);
	max = stack_max(*a);
	while (max->r_pos != 0)
	{
		if (max->r_pos > stack_size(*a) / 2)
			stack_move(a, b, RRA);
		else
			stack_move(a, b, RA);
	}
	stack_move(a, b, PB);
	sort_3(a, b);
	stack_move(a, b, PA);
	stack_move(a, b, RA);
	return (0);
}

static int	sort_5(t_stack **a, t_stack **b)
{
	t_stack *max;

	if (!a || !b)
		return (-1);
	max = stack_max(*a);
	while (max->r_pos != 0)
	{
		if (max->r_pos > stack_size(*a) / 2)
			stack_move(a, b, RRA);
		else
			stack_move(a, b, RA);
	}
	stack_move(a, b, PB);
	sort_4(a, b);
	stack_move(a, b, PA);
	stack_move(a, b, RA);
	return (0);
}

static int	recursive_split(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int min;

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

int	merge_sort(t_stack **a, t_stack **b)
{
	int		median;
	t_stack	*node;

	median = stack_size(*b) / 2;
	while (*b)
	{
		calculate_cost(*a, *b, median);
		node = min_cost(*b);
		while (*b != node)
		{
			if ((*b)->top_cost)
				stack_move(*a, *b, (*b)->move);
			else if ((*b)->r_pos < median)
				stack_move(*a, *b, RB);
			else
				stack_move(*a, *b, RB);
		}
	}
}
	

static int	sort(t_stack **a, t_stack **b)
{
	recursive_split(a, b, stack_size(*a));
	if (!(*a)->next)
		return (0);
	else if (stack_size(*a) == 2 && !is_sorted(*a))
		stack_move(a, b, SA);
	else
		sort_3(a, b);
	merge_sort(a, b);
	return (0);
}

int	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (!a)
		return (-1);
	if (is_sorted(*a))
		return (0);
	if (size == 2 && (*a)->f_pos == 1)
		stack_move(a, b, SA);
	else if (size == 3 && !sort_3(a, b))
		return (0);
	else if (size == 4 && !sort_4(a, b))
		return (0);
	else if (size == 5 && !sort_5(a, b))
		return (0);
	else
		sort(a, b);
	return (-1);
}
