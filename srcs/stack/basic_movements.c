/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:26:14 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/04 23:01:31 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push(t_stack **src, t_stack **dst)
{
	if (!src || !dst)
		return (-1);
	if (!*src)
		return (0);
	if (!*dst)
	{
		*dst = *src;
		*src = (*src)->next;
		if (*src)
			(*src)->prev = NULL;
		(*dst)->next = NULL;
		return (0);
	}
	(*dst)->prev = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	(*dst)->prev->next = *dst;
	*dst = (*dst)->prev;
	return (0);
}

int	stack_rotate(t_stack **src)
{
	t_stack	*last;

	if (!src)
		return (-1);
	if (!*src || !(*src)->next)
		return (0);
	last = stack_last(*src);
	last->next = (*src);
	(*src) = (*src)->next;
	last->next->next = NULL;
	last->next->prev = last;
	(*src)->prev = NULL;
	return (0);
}

int	stack_rev_rotate(t_stack **src)
{
	t_stack	*last;

	if (!src)
		return (-1);
	if (!*src || !(*src)->next)
		return (0);
	last = stack_last(*src);
	last->next = (*src);
	last->prev->next = NULL;
	(*src)->prev = last;
	last->prev = NULL;
	(*src) = (*src)->prev;
	return (0);
}

int	stack_swap(t_stack **src)
{
	t_stack	*first;
	t_stack	*second;

	if (!src)
		return (-1);
	if (!*src || !(*src)->next)
		return (0);
	first = *src;
	second = (*src)->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	(*src) = second;
	return (0);
}
