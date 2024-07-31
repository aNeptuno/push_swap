/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:07:22 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/31 18:26:37 by adiban-i         ###   ########.fr       */
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

static void	push_to_a(t_stack *stack_a, t_stack *stack_b, t_program_data *pd)
{
	int	rep;

	rep = 0;
	if (stack_a->top != stack_b->top->target)
	{
		if (stack_a->top->index >= stack_a->median)
		{
			while (rep < stack_a->top->index)
			{
				ra(pd);
				rep++;
			}
		}
		else
		{
			while (rep < stack_a->size - 1 - stack_a->top->index)
			{
				rra(pd);
				rep++;
			}
		}
	}
	pa(pd, 1);
}

static void	min_on_top(t_stack *a, t_program_data *pd)
{
	t_node	*min;

	min = find_smallest(a);
	while (a->top != min)
	{
		if (min->index < a->median)
			rra(pd);
		else
			ra(pd);
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b, t_program_data *pd)
{
	if (stack_a->size >= 5)
		pb(pd, 2);
	else
		pb(pd, 1);
	while (stack_a->size > 3)
	{
		set_initial_data(stack_a, stack_b, 1);
		push_to_b(stack_a, stack_b, pd);
	}
	small_sort(stack_a, pd);
	/* while (stack_b->size > 0)
	{
		set_initial_data(stack_a, stack_b, 0);
		push_to_a(stack_a, stack_b, pd);
	} */
	min_on_top(stack_a, pd);
}
