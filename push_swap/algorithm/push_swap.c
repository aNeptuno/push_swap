/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:07:22 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/04 13:32:11 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	rr_or_rrr_reset_index(stack_a, stack_b, pd, cheapest);
	if (cheapest->index <= stack_a->median)
		while (stack_a->top != cheapest)
			ra(pd, 1);
	else
		while (stack_a->top != cheapest)
			rra(pd, 1);
	if (cheapest->target->index <= stack_b->median)
		while (stack_b->top != cheapest->target)
			rb(pd, 1);
	else
		while (stack_b->top != cheapest->target)
			rrb(pd, 1);
	pb(pd, 1, 1);
}

static void	push_to_a(t_stack *stack_a, t_stack *stack_b, t_program_data *pd)
{
	while (stack_a->top != stack_b->top->target)
	{
		if (stack_b->top->target->index <= stack_a->median)
			ra(pd, 1);
		else
			rra(pd, 1);
	}
	pa(pd, 1, 1);
}

static void	min_on_top(t_stack *a, t_program_data *pd)
{
	t_node	*min;

	set_indexes(a, 0);
	a->median = a->size / 2;
	min = find_smallest(a);
	while (a->top != min)
	{
		if (min->index <= a->median)
			ra(pd, 1);
		else
			rra(pd, 1);
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b, t_program_data *pd)
{
	if (stack_a->size >= 5)
		pb(pd, 2, 1);
	else
		pb(pd, 1, 1);
	while (stack_a->size > 3)
	{
		set_initial_data(stack_a, stack_b, 1);
		push_to_b(stack_a, stack_b, pd);
	}
	small_sort(stack_a, pd);
	while (stack_b->size > 0)
	{
		set_initial_data(stack_a, stack_b, 0);
		push_to_a(stack_a, stack_b, pd);
	}
	min_on_top(stack_a, pd);
}
