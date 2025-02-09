/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:39:13 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/08 23:37:13 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num > 0)
		return (num);
	else
		return (-num);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_stack	*min_cost(t_stack *node, int pivot_min, int pivot_max)
{
	t_stack	*aux;

	aux = NULL;
	while (node)
	{
		if (!aux && node->f_pos >= pivot_min && node->f_pos <= pivot_max)
			aux = node;
		if (aux && aux->cost > node->cost && node->f_pos >= pivot_min
			&& node->f_pos <= pivot_max)
			aux = node;
		node = node->next;
	}
	return (aux);
}
