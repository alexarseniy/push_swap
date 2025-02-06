/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:25:40 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/05 03:43:52 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (init_stack(&a, argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	stack_print(a);
	sort_stack(&a, &b);
	ft_printf("\nStack a: \n");
	stack_print(a);
	ft_printf("\nStack b: \n");
	stack_print(b);
	stack_free(a);
	stack_free(b);
	return (0);
}
