/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:09:22 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/05 21:31:24 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
 * Function: stack_print
 * ---------------------
 *  This function takes a node to a double linked list-based stack, check if
 *  exists and get the first element. After that, print all the nodes and its
 *  values. If it receive NULL, do nothing.
 *
 * *node: Node to the dobule linked list-based stack.
 *
 * return: nothing.
 */
void	stack_print(t_stack *node)
{
	if (!node)
		return ;
	node = stack_first(node);
	while (node)
	{
		ft_printf("Node [%i]: value [%i], ", node->r_pos, node->value);
		ft_printf("final index [%i]\n", node->f_pos);
		node = node->next;
	}
}

/*
 * Function: stack_free
 * --------------------
 *  This function takes a node to a double linked list-based stack, check if
 *  exists and get the first element. After that, free all nodes and clean the
 *  memmory. If it receive NULL, do nothing.
 *
 *  *node: Node to the double linked list-based stack to free.
 *
 *  return: nothing.
 */
void	stack_free(t_stack *node)
{
	t_stack	*aux;

	if (!node)
		return ;
	while (node)
	{
		aux = node->next;
		node->next = NULL;
		node->prev = NULL;
		node->value = 0;
		node->cost = 0;
		node->r_pos = 0;
		node->f_pos = 0;
		free(node);
		node = aux;
	}
}

bool	is_sorted(t_stack *s)
{
	while (s && s->next)
	{
		if (s->f_pos != s->next->f_pos - 1)
			return (false);
		s = s->next;
	}
	return (true);
}
