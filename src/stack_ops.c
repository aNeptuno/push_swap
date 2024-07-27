/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:52:37 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 15:52:57 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push(t_stack* stack, int data)
{
    t_node* new_node;
	
	new_node = (t_node*)malloc(sizeof(t_node));
    if (!new_node)
	{
        ft_putstr("Failed to allocate memory for new node\n");
        return;
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}
