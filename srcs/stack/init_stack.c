/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:04:18 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/02 02:20:21 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "checker.h"

static const char	**init_nums(int argc, char **argv)
{
	int		i;
	char	**result;

	if (argc < 2 || !argv)
		return (NULL);
	if (argc == 2)
		result = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		while (argv[i])
			i++;
		result = ft_calloc(i, sizeof(char *));
		if (!result)
			return (NULL);
		i = 0;
		while (*(++argv))
		{
			result[i] = ft_strdup(*argv);
			if (!result[i++])
				return (ft_free_matrix((void **)result, NULL), NULL);
		}
	}
	return ((const char **) result);
}

int	init_stack(t_stack **stack, int argc, char **argv)
{
	int			i;
	const char	**nums;

	i = 0;
	if (!stack || !argv)
		return (-1);
	nums = init_nums(argc, argv);
	if (!nums || !is_valid_input(nums))
		return (ft_free_matrix((void **)nums, NULL), -1);
	while (nums[i])
	{
		if (stack_add_last(stack, stack_new(ft_atoi(nums[i]))) == -1)
			return (ft_free_matrix((void **)nums, NULL), -1);
		i++;
	}
	ft_free_matrix((void **)nums, NULL);
	return (0);
}
