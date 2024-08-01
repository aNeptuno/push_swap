/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:42:30 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/01 11:52:40 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns 1 if n > m | 0 if they are equal | -1 if n < m
int	data_compare(t_node *node_n, t_node *node_m)
{
	int	n;
	int	m;

	if (!node_m)
		return (1);
	n = node_n->data;
	m = node_m->data;
	if (n > m)
		return (1);
	else if (n < m)
		return (-1);
	else
		return (0);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current;
	int		is_sorted;

	is_sorted = 1;
	current = stack->top;
	while (current && is_sorted)
	{
		if (data_compare(current, current->next) > 0)
			is_sorted = 0;
		current = current->next;
	}
	return (is_sorted);
}

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
		if (current->target != NULL)
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
		if (data_compare(current, smallest) < 0)
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
	int		biggest;

	current_b = b_node;
	current_a = stack_a->top;
	while (current_b)
	{
		while (current_a)
		{
			if (data_compare(current_a, current_b) > 0)
			{
				if (!current_b->target)
					current_b->target = current_b;
				else if (data_compare(current_a, current_b->target) > 0)
					current_b->target = current_a;
			}
			current_a = current_a->next;
		}
		if (!current_b->target)
			current_b->target = find_smallest(stack_a);
		current_b = current_b->next;
	}
}
