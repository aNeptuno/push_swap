/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:07:22 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/30 16:14:39 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indexes(t_stack *stack)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}

static t_node	*get_cheapest_node(t_node *node)
{
	t_node	*current;

	current = node;
	while (current && !current->cheapest)
		current = current->next;
	return (current);
}

static void	push_to_b(t_stack *stack_a, t_stack *stack_b, t_program_data *pd)
{
	t_node	*cheapest;

	cheapest = get_cheapest_node(stack_a->top);
	if (cheapest->index >= stack_a->median)
	{
		while (stack_a->top != cheapest)
			ra(pd);
	}
	else
	{
		while (stack_a->top != cheapest)
			rra(pd);
	}
	if (cheapest->target->index >= stack_b->median)
	{
		while (stack_b->top != cheapest->target)
			rb(pd);
	}
	else
	{
		while (stack_b->top != cheapest->target)
			rrb(pd);
	}
	pb(pd, 1);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b, t_program_data *pd)
{
	if (stack_a->size >= 5)
		pa(pd, 2);
	else
		pa(pd, 1);
	while (stack_a->size > 3)
	{
		set_initial_data(stack_a, stack_b);
		push_to_b(stack_a, stack_b, pd);
	}
	small_sort(stack_a, pd);
	// push back into a
	// min on top (a)
}