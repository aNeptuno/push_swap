/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:28:21 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/28 13:30:32 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *stack_a, t_program_data *pd)
{
	if (data_compare(stack_a->top, stack_a->top->next))
			pb(pd, 2);
		else
		{
			pb(pd, 2);
			sa(pd);
		}
}

static t_node	*find_biggest(t_stack *stack)
{
	if (data_compare(stack->top, stack->top->next))
	{
		if (data_compare(stack->top, stack->top->next->next))
			return (stack->top);
		else
			return (stack->top->next->next);
	}
	else
	{
		if (data_compare(stack->top->next, stack->top->next->next))
			return (stack->top->next);
		else
			return (stack->top->next->next);
	}
}

// Small sort when size == 2 or size == 3
void	small_sort(t_stack *stack_a, t_program_data *pd)
{
	t_node	*biggest;

	if (stack_a->size == 2)
	{
		sort_two(stack_a, pd);
	}
	else
	{
		biggest = find_biggest(stack_a);
		if (stack_a->top == biggest)
			pb(pd, 1);
	}
}