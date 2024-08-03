/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:28:21 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/01 13:52:23 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *stack_a, t_program_data *pd)
{
	if (stack_a->top->data > stack_a->top->next->data)
		sa(pd);
}

t_node	*find_biggest(t_stack *stack)
{
	t_node	*biggest;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	if (stack->size == 1)
		return (stack->top);
	biggest = stack->top;
	current = stack->top->next;
	while (current)
	{
		if (current->data > biggest->data)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

// Small sort when size == 2 or size == 3
void	small_sort(t_stack *stack_a, t_program_data *pd)
{
	t_node	*biggest;

	if (stack_a->size == 2)
		sort_two(stack_a, pd);
	else
	{
		biggest = find_biggest(stack_a);
		if (stack_a->top == biggest)
			ra(pd);
		else if (stack_a->top->next == biggest)
			rra(pd);
		if (stack_a->top->data > stack_a->top->next->data)
			sa(pd);
	}
}
