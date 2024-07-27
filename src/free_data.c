/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:50:31 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 20:21:11 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	free_stack(t_stack *stack)
{
    t_node	*current;
    t_node	*next;
	
	current = malloc(sizeof(t_node));
	if (current == NULL)
		return ;
	current = stack->top;
    while (current)
	{
		next = current->next;
		free(current);
		current = next;
    }
	stack->top = NULL;
}

void free_data(t_program_data *prog_data)
{
	free_stack(prog_data->stack_a);
	free_stack(prog_data->stack_b);
	free(prog_data->stack_a);
    free(prog_data->stack_b);
}
