/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:05:12 by olarseni          #+#    #+#             */
/*   Updated: 2024/11/26 21:03:22 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "libft.h"

/*
 * Function: stack_new
 * -------------------
 * Creates a new stack node with the input value 'value' and
 * initializes the new node. This function reserve heap memory using
 * ft_calloc.
 *
 * value: Integer value that will initializates the node's 'value'
 *
 * return: Return t_stack *new_node or NULL if ft_calloc fails
 */
t_stack	*stack_new(int value)
{
	t_stack	*new_node;

	new_node = ft_calloc(sizeof(*new_node), 1);
	if (!new_node)
		return (NULL);
	new_node->value = value;
	return (new_node);
}

/*
 * Function: stack_last
 * --------------------
 * This function returns the last element of the stack 'stack'. While the stack
 * isn't empty and the next element exists, the function will go to the next
 * element.
 *
 * stack: stack node from where the function will start to find the last node.
 *
 * return: return the last element or NULL if stack has no elements
 *
 * Note: This function implicitly knows when the stack is empty, as it's value
 * will be NULL.
 */
t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

/*
 * Function: stack_add_last
 * ------------------------
 * This function takes the pointer to the 'dest' stack, and add the new node
 * 'new' at the end of it. The pointer to 'dest' must exist. If 'dest' doesn't
 * or new is NULL, the function does nothing.
 *
 * dest: pointer to the dest stack. It doesn't matter if the node pointed by
 *       'dest' is the first one or another one.
 * new: New node that will be added to the 'dest' stack.
 *
 * returns: No return as it add the new element directly using pointers.
 */
void	stack_add_last(t_stack **dest, t_stack *new)
{
	t_stack	*last;

	if (!dest || !new)
		return ;
	if (!*dest)
	{
		*dest = new;
		return ;
	}
	last = stack_last(*dest);
	if (!last)
		return ;
	last->next = new;
	new->prev = last;
}

/*
 * Function: stack_size
 * --------------------
 * This function returns the size of the stack received as parameter. It assumes
 * that the node 'stack' is the first element, otherwise, the count will return
 * the number of elements starting from this node.
 *
 * stack: The node where the function will start from to count the stack's size
 *
 * return: Integer number 'size' that has the number of elements counted.
 */
int	stack_size(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

/*
 * Function: stack_clear
 * ---------------------
 * Clears all elements from the stack, freeing the memmory and
 * clearing the memmory by setting to NULL all pointers using an auxiliar node.
 * The param 'stack' is a pointer to the first element of the stack, otherwise 
 * the behavior is undefined.
 *
 * stack: Pointer to the first element of the stack.
 *
 * returns: This function returns NULL after clearing the memory.
 */
void	*stack_clear(t_stack **top)
{
	t_stack	*node;

	if (!top || !(*top))
		return (NULL);
	while (*top)
	{
		node = (*top)->next;
		(*top)->next = NULL;
		(*top)->prev = NULL;
		free(*top);
		*top = node;
	}
	return (NULL);
}
