/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 02:25:05 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/09 01:35:22 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_cost_b(t_stack *b, int median, int size_b)
{
	if (b->r_pos > median)
		return (b->r_pos - size_b);
	else
		return (b->r_pos);
}

static int	calculate_cost_a(t_stack *a, t_stack *b)
{
	int		size_a;
	t_stack	*a_min;
	t_stack	*a_max;

	size_a = stack_size(a);
	a_min = stack_min(a);
	a_max = stack_max(a);
	while (a && a->next)
	{
		if (b->f_pos > a->f_pos && b->f_pos < a->next->f_pos)
		{
			a = a->next;
			break ;
		}
		else if ((b->f_pos < a->f_pos && b->f_pos > stack_last(a)->f_pos)
			|| (a->f_pos == a_max->f_pos && b->f_pos > a->f_pos)
			|| (a->f_pos == a_min->f_pos && b->f_pos < a->f_pos))
			break ;
		else
			a = a->next;
	}
	if (a->r_pos <= ((size_a - 1) / 2))
		return (a->r_pos);
	return (a->r_pos - size_a);
}

static void	set_move(t_stack *b, int cost_a, int cost_b)
{
	if (cost_b > 0 && cost_a > 0)
		b->move = RR;
	else if (cost_b < 0 && cost_a < 0)
		b->move = RRR;
	else if (cost_a > 0)
		b->move = RA;
	else if (cost_a < 0)
		b->move = RRA;
	else if (cost_b < 0)
		b->move = RRB;
	else if (cost_b > 0)
		b->move = RB;
}

void	calculate_merge_cost(t_stack *a, t_stack *b, int median, int size_b)
{
	int	cost_b;
	int	cost_a;

	while (b)
	{
		cost_b = calculate_cost_b(b, median, size_b);
		cost_a = calculate_cost_a(a, b);
		set_move(b, cost_a, cost_b);
		if (b->move == RR || b->move == RRR)
			b->cost = ft_abs(cost_a) + ft_abs(cost_b)
				- ft_min(ft_abs(cost_b), ft_abs(cost_a));
		else
			b->cost = ft_abs(cost_b) + ft_abs(cost_a);
		b = b->next;
	}
}
