/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:20:23 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/01 14:26:37 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Target is closest smaller number on stack b.
///        If no smaller number found, target is biggest
/// @param node top node from stack to set targets
/// @param stack stack to target
static void	set_a_targets(t_node *node, t_stack *stack)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = node;
	current_b = stack->top;
	while (current_a)
	{
		//printf("current a: %d\n",current_a->data);
		current_b = stack->top;
		while (current_b)
		{
			//printf("--> current_b->data = %d\n", current_b->data);
			if (current_b->data < current_a->data)
			{
				if (current_a->target == NULL)
				{
					//printf("--> current a no tiene target, le asigno el valor de current b\n");
					current_a->target = current_b;
				}
				else if (current_b->data > current_a->target->data)
				{
					//printf("entro a elseif: hay target, pero mi nuevo valor es mayor que el target (y menor que current a)\n");
					current_a->target = current_b;
				}
			}
			current_b = current_b->next;
		}
		if (current_a->target == NULL)
		{
			//printf("entra a no target dsp de while\n");
			current_a->target = find_biggest(stack);
		}
		//printf("a node: %d | target b node: %d\n", current_a->data, current_a->target->data);
		current_a = current_a->next;
	}
}

static int	get_push_cost_target(t_node *node_b, t_stack *stack_b)
{
	int		push_cost;

	push_cost = 0;
	if (node_b->index <= stack_b->median)
		push_cost = node_b->index;
	else
		push_cost = stack_b->size - node_b->index;
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
			current->push_cost = stack_a->size - current->index;
		current->push_cost += get_push_cost_target(current->target, stack_b);
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
	current = min_node->next;
	if (current == NULL)
		return ;
	while (current)
	{
		current->cheapest = 0;
		if (current->push_cost < min_cost)
		{
			min_node->cheapest = 0;
			current->cheapest = 1;
			min_node = current;
		}
		current = current->next;
	}
}

/// @brief Initialize indexes, median, targets, push cost and cheapest nodes
/// @param a indicates wheter is stack a init or stack b init
void	set_initial_data(t_stack *stack_a, t_stack *stack_b, int a)
{
	stack_a->median = stack_a->size / 2;
	stack_b->median = stack_b->size / 2;
	set_indexes(stack_a, 1);
	set_indexes(stack_b, 1);
	if (a)
	{
		set_a_targets(stack_a->top, stack_b);
		set_push_cost(stack_a, stack_b);
		set_cheapest(stack_a->top);
	}
	else
		set_b_targets(stack_b->top, stack_a);
}
