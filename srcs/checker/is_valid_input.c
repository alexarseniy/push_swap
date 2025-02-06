/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:10:44 by olarseni          #+#    #+#             */
/*   Updated: 2025/02/02 02:22:04 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
 * Function: is_valid_num
 * ----------------------
 *  THis function check if the number is a valid number, that means that is
 *  in int range number and it has no other chars. If num is NULL or is invalid
 *  returns false, otherwise return true.
 *
 *  *num: char pointer that contains the number to check
 *
 *  return: return false if num is null or has invalid chars or is in invalid
 *  range. Otherwise, it returns true
 */
static bool	is_valid_num(const char *num)
{
	char	*parsed_num;
	bool	is_valid;

	if (!num)
		return (false);
	parsed_num = ft_itoa(ft_atoi(num));
	if (!parsed_num || ft_strncmp(num, parsed_num, ft_strlen(num)))
		return (free(parsed_num), false);
	if (ft_strncmp(num, parsed_num, ft_strlen(num)))
		is_valid = false;
	else
		is_valid = true;
	free(parsed_num);
	return (is_valid);
}

/*
 * Function is_duplicated_num
 * --------------------------
 *  This functions takes the number to check in the nums array. The number will
 *  be the first element of nums array, so it will allways start to check from
 *  the next element of the array.
 *
 * *num: a char pointer that contains the number chars.
 * **nums: a matrix whose every row will be a number to compare with num var.
 *
 * returns: false if num or nums is null or void. Also return false if the num
 * already exists in the nums matrix. Otherwise, return true.
 */
static bool	is_duplicated_num(const char *num, const char **nums)
{
	int	i;

	if (!num || !nums || !*nums)
		return (NULL);
	i = 1;
	while (nums[i] && ft_atoi(num) != ft_atoi(nums[i]))
		i++;
	if (nums[i])
		return (true);
	return (false);
}

/*
 * Function: is_valid_input
 * ------------------------
 * This function takes the numbers to pass to the stack and validate them. If 
 * nums are NULL, return false. Then check if it is a valid number of each elem
 * in nums, and if it is not duplicated. In case that is invalid or duplicated
 * return false.
 *
 * char **nums: numbers that are the input for the program.
 *
 *  return: true if they are valid numbers, false if not.
 */
bool	is_valid_input(const char **nums)
{
	int	i;

	i = 0;
	if (!nums)
		return (false);
	while (nums[i])
	{
		if (!is_valid_num(nums[i]) || is_duplicated_num(nums[i], nums + i))
			return (false);
		i++;
	}
	return (true);
}
