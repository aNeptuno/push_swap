/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:20:23 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/30 15:42:52 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Target is closest smaller number on stack b.
///        If no smaller number found, target is biggest
/// @param a_node stack a top node
static void	set_targets(t_node *a_node, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = a_node;
	current_b = stack_b->top;
	while (current_a)
	{
		while (current_b)
		{
			if (data_compare(current_b, current_a) < 0)
			{
				if (!current_a->target)
					current_a->target = current_b;
				else if (data_compare(current_b, current_a->target) > 0)
					current_a->target = current_b;
			}
			current_b = current_b->next;
		}
		if (!current_a->target)
			current_a->target = find_biggest(stack_b);
		current_a = current_a->next;
	}
}

static int	set_push_cost_target(t_node *node_b, t_stack *stack_b)
{
	int		push_cost;

	push_cost = 0;
	if (node_b->index <= stack_b->median)
		push_cost = node_b->index;
	else
		push_cost = stack_b->size - 1 - node_b->index;
	return (push_cost);
}

static void	set_push_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	current = stack_a->top;
	while (current)
	{
		if (current->index <= stack_a->median)
			current->push_cost = current->index;
		else
			current->push_cost = stack_a->size - 1 - current->index;
		current->push_cost += set_push_cost_target(stack_b->top, stack_b);
		current = current->next;
	}
}

/// @brief sets 1 to the cheapest node and 0 to the rest
/// @param node top node of a stack 
static void	set_cheapest(t_node *node)
{
	t_node	*current;
	t_node	*min_node;
	int		min_cost;

	min_node = node;
	min_cost = min_node->push_cost;
	min_node->cheapest = 1;
	current = node;
	while (current)
	{
		current->cheapest = 0;
		if (current->push_cost < min_cost)
		{
			current->cheapest = 1;
			min_node->cheapest = 0;
			min_node = current;
		}
		current = current->next;
	}
}

void	set_initial_data(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->median = stack_a->size / 2;
	stack_b->median = stack_b->size / 2;
	set_indexes(stack_a);
	set_indexes(stack_b);
	set_targets(stack_a->top, stack_b);
	set_push_cost(stack_a, stack_b);
	set_cheapest(stack_a->top);
}
