/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:42:30 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/02 15:31:24 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Set indexes of stack, also set cheapest as 0
/// @param reset_target set all nodes target to NULL
void	set_indexes(t_stack *stack, int reset_target)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		current->index = i;
		current->cheapest = 0;
		i++;
		if (reset_target)
			current->target = NULL;
		current = current->next;
	}
}

t_node	*find_smallest(t_stack *stack)
{
	t_node	*smallest;
	t_node	*current;

	smallest = stack->top;
	current = stack->top->next;
	while (current)
	{
		if (current->data < smallest->data)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

/// @brief Target is closest BIGGEST number on stack a.
///        If no smaller number found, target is smallest
/// @param node top node from stack to set targets
/// @param stack stack to target
void	set_b_targets(t_node *b_node, t_stack *stack_a)
{
	t_node	*current_a;
	t_node	*current_b;

	current_b = b_node;
	current_a = stack_a->top;
	while (current_b)
	{
		current_a = stack_a->top;
		current_b->target = NULL;
		while (current_a)
		{
			if (current_a->data > current_b->data)
			{
				if (current_b->target == NULL)
					current_b->target = current_a;
				else if (current_a->data < current_b->target->data)
					current_b->target = current_a;
			}
			current_a = current_a->next;
		}
		if (current_b->target == NULL)
			current_b->target = find_smallest(stack_a);
		current_b = current_b->next;
	}
}

void	rr_or_rrr_reset_index(t_stack *stack_a,
			t_stack *stack_b, t_program_data *pd, t_node *cheapest)
{
	if (cheapest->index <= stack_a->median
		&& cheapest->target->index <= stack_b->median)
		while (stack_a->top != cheapest && stack_b->top != cheapest->target)
			rr(pd);
	else if (cheapest->index > stack_a->median
		&& cheapest->target->index > stack_b->median)
		while (stack_a->top != cheapest && stack_b->top != cheapest->target)
			rrr(pd);
	set_indexes(stack_a, 0);
	set_indexes(stack_b, 0);
}
