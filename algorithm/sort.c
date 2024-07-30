/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:30:27 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/30 15:08:34 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b, t_program_data *pd)
{
	if (stack_a->size <= 3)
		small_sort(stack_a, pd);
	else
		push_swap(stack_a, stack_b, pd);
}
