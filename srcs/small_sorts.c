/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:48:43 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/08 03:49:08 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_stack **a, t_stack **b)
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

int	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*max;

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

int	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*max;

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
