/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:20:55 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/27 20:17:05 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *small_sort(t_stack *a)
{
	if (!a)
		return (NULL);
	while (!is_sorted(a))
	{
		if (a->next && a->value < a->next->value)
			select_move(&a, NULL, RRA);
		else if (a->next && a->value > a->next->value)
			select_move(&a, NULL, SA);
	}
	return (a);
}

t_stack *mid_sort(t_stack *a, t_stack *b)
{
	if (!a)
		return (NULL);
	if (is_sorted(a))
		return (a);
	while (stack_size(a) != 3)
		select_move(&a, &b, PB);
	a = small_sort(a);
	while (stack_size(b))
	{
		if (b->index == a->index + 1)
		{
			select_move(&a, &b, RA);
			select_move(&a, &b, PA);
		}
		else if (b->index == a->index - 1)
			select_move(&a, &b, PA);
		else
			select_move(&a, &b, RRA);
	}
	while (!is_sorted(a))
		select_move(&a, &b, RA);
	return (a);
}

t_stack *big_sort(t_stack *a, t_stack *b)
{
	//TODO
	if (!b)
		return (a);
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
