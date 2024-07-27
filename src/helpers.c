/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:54:41 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 15:54:57 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void print_stack(t_stack *s)
{
	t_node	*current;

	current = s->top;
	printf("stack: "); 
	while (current)
	{
		printf("%d, ", current->data);
		current = current->next;
	}
	printf("\n"); 
}
