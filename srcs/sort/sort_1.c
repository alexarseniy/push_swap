/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:20:55 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/27 07:59:14 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *small_sort(t_stack *a)
{
	if (!a)
		return (NULL);
	if (a && a->next && !a->next->next && a->index < a->next->index)
		return (a);
	if (a && a->next && !a->next->next && a->index > a->next->index)
		return (execute_move(&a, NULL, SA), a);
	if (a && a->next && a->next->next && a->index == 0 && a->next->index == 2)
	{
		execute_move(&a, NULL, RRA);
		execute_move(&a, NULL, SA);
	}
	if (a && a->next && a->next->next && a->index == 1 && a->next->index == 0)
		execute_move(&a, NULL, SA);
	if (a && a->next && a->next->next && a->index == 1 && a->next->index == 2)
		execute_move(&a, NULL, RRA);
	if (a && a->next && a->next->next && a->index == 2 && a->next->index == 0)
		execute_move(&a, NULL, RA);
	if (a && a->next && a->next->next && a->index == 2 && a->next->index == 1)
	{
		execute_move(&a, NULL, SA);
		execute_move(&a, NULL, RRA);
	}
	return (a);
}

t_stack *mid_sort(t_stack *a, t_stack *b)
{
	t_move	next_move;

	if (!a)
		return (NULL);
	if (is_sorted(a))
		return (a);
	while (stack_size(a) != 3)
		execute_move(&a, &b, PB);
	a = small_sort(a);
	while (stack_size(b) || !is_sorted(a))
	{
		next_move = select_next_move(a, b);
		execute_move(&a, &b, next_move);
	}
	return (a);
}

t_stack *big_sort(t_stack *a, t_stack *b)
{
	if (!a)
		return (NULL);
	if (is_sorted(a))
		return (a);
	while (stack_size(a) != 3)
	{
		if (!b)
			execute_move(&a, &b, PB);
		if (b && a->index > b->index)
			execute_move(&a, &b, PB);
		else
		{
			execute_move(&a, &b, PB);
			execute_move(&a, &b, RB);
		}
	}
	return (a);
}

t_stack	*push_swap(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (stack_size(a) <= 3)
		return (small_sort(a));
	if (stack_size(a) > 3 && stack_size(a) <= 5)
		return (mid_sort(a, b));
	return (big_sort(a, b));
}
