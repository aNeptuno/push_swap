/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:45:32 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/04 15:01:40 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

/// @brief Compares two strings
/// @return Returns 0 if they are equal, otherwise, returns the diference
int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
