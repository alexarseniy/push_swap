/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:26:13 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/08 03:48:24 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include "stack.h"

int		sort_stack(t_stack **a, t_stack **b);
void	calculate_merge_cost(t_stack *a, t_stack *b, int median);
int		big_sort(t_stack **a, t_stack **b);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int num);
t_stack	*min_cost(t_stack *node);
int		sort_5(t_stack **a, t_stack **b);
int		sort_4(t_stack **a, t_stack **b);
int		sort_3(t_stack **a, t_stack **b);

#endif
