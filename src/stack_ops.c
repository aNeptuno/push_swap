/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:52:37 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/02 14:24:38 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Add node to stack
/// @param stack stack to add new node
/// @param data data to the new node
void	push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = stack->top;
	new_node->prev = NULL;
	if (stack->top != NULL)
		stack->top->prev = new_node;
	stack->top = new_node;
	stack->size++;
}

void	pop_first(t_stack *stack)
{
	t_node	*top_node;

	if (stack->top == NULL)
		return ;
	top_node = stack->top;
	stack->top = top_node->next;
	if (stack->top != NULL)
		stack->top->prev = NULL;
	free(top_node);
	stack->size--;
}
