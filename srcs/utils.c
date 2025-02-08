/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:39:13 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/08 03:52:29 by olarseni         ###   ########.fr       */
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

t_stack	*min_cost(t_stack *node)
{
	t_stack	*aux;

	aux = node;
	while (node)
	{
		if (aux->cost > node->cost)
			aux = node;
		node = node->next;
	}
	return (aux);
}
