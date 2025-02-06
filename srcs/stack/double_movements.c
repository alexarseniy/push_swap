/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:57:12 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/02 14:00:57 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_sswap(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return (-1);
	if (stack_swap(a) == -1 || stack_swap(b) == -1)
		return (-1);
	return (0);
}

int	stack_rrotate(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return (-1);
	if (stack_rotate(a) == -1 || stack_rotate(b) == -1)
		return (-1);
	return (0);
}

int	stack_rev_rrotate(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return (-1);
	if (stack_rev_rotate(a) == -1 || stack_rev_rotate(b) == -1)
		return (-1);
	return (0);
}
