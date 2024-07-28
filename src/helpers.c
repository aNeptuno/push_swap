/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:54:41 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/28 13:12:31 by adiban-i         ###   ########.fr       */
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

// Returns 1 if n > m | 0 if they are equal | -1 if n < m
int	data_compare(t_node *node_n, t_node *node_m)
{
	int	n;
	int	m;

	n = node_n->data;
	m = node_m->data;
	if (n > m)
		return (1);
	else if (n < m)
		return (-1);
	else
		return (0);
}
