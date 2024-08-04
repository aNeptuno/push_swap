/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:54:41 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/04 14:28:18 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s, char ch)
{
	t_node	*current;

	current = s->top;
	printf("stack %c: ", ch);
	while (current)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
	printf("\n");
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*current;
	int		is_sorted;

	is_sorted = 1;
	current = stack->top;
	while (current && is_sorted)
	{
		if (current->next != NULL)
			if (current->data > current->next->data)
				is_sorted = 0;
		current = current->next;
	}
	return (is_sorted);
}

void	init_program_data(t_program_data *prog_data)
{
	prog_data->stack_a = malloc(sizeof(t_stack));
	prog_data->stack_b = malloc(sizeof(t_stack));
	if (prog_data->stack_a == NULL || prog_data->stack_b == NULL)
		return ;
	prog_data->stack_a->top = NULL;
	prog_data->stack_b->top = NULL;
	prog_data->stack_a->size = 0;
	prog_data->stack_b->size = 0;
	prog_data->valid_input = 1;
	prog_data->input_is_string = 0;
}
