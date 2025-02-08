/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:21:05 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/08 03:53:34 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
 * Function: stack_new
 * -------------------
 *  This function create a new node for a double linked list-based stack, set
 *  all values to 0, set the value to value param and return the new node. If
 *  the memory allocation fails, it return NULL.
 *
 *  value: value of the new node.
 *
 *  return: new node created and with its values initialized or NULL if it fails.
 */
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	new->cost = 0;
	new->f_pos = 0;
	new->r_pos = 0;
	new->w_stack = STACK_A;
	return (new);
}

/*
 * Function: stack_first
 * ---------------------
 *  This function takes a node of the stack returns the first element 
 *  of the stack or NULL if the node is NULL.
 *
 *  *node: Pointer to a double linked list-based stack node.
 *
 *  return: the first element or NULL if the node is NULL.
 */
t_stack	*stack_first(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->prev)
		node = node->prev;
	return (node);
}

/*
 * Function: stack_last
 * --------------------
 *  Function that takes a node of the stack and returns the last node that is in
 *  the stack.
 *
 * *node: Node of a double linked list-based stack
 *
 * return: the last node of the stack.
 */
t_stack	*stack_last(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

/*
 * Function stack_size
 * -------------------
 *  this function takes the node of the stack and count the number of elements
 *  that are stored in its stack starting from the node. If the user wants to
 *  know the full size, he must to ensure that node is the first element of the
 *  stack.
 *
 * *node: pointer to a double linked list-based stack node.
 *
 * return: number of elements that are in the stack starting to count from the
 * node.
 */
int	stack_size(t_stack *node)
{
	int	i;

	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

/*
 * Function: stack_add_last
 * ------------------------
 *  This function receives a pointer to a stack node and the new node.
 *  The new node will be added to the end of the stack. If the node pointer is
 *  NULL or the new node is NULL, the function won't do anything and return -1
 *  otherwise if the stack doesn't have any element, the new node will be the 
 *  first node or the new node will be added to the *next of the last node. Also
 *  it set the real position inside the stack.
 *
 *  **node: pointer to the pointer of the node of the double linked list-based
 *  stack.
 *  *new: New node of the double linked list-based stack that will be added.
 *
 *  return: -1 if the new is NULL or the pointer to the node is NULL. 0 when the
 *  node is added successfully.
 */

int	stack_add_last(t_stack **node, t_stack *new)
{
	t_stack	*last;

	if (!node || !new)
		return (-1);
	if (!*node)
	{
		*node = new;
		return (0);
	}
	last = stack_last(*node);
	last->next = new;
	new->prev = last;
	new->r_pos = stack_size(stack_first(*node)) - 1;
	while (last)
	{
		if (last->value > new->value)
			last->f_pos++;
		else
			new->f_pos++;
		last = last->prev;
	}
	return (0);
}
