/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:47:35 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/08 03:49:10 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		big_sort(a, b);
	return (-1);
}
