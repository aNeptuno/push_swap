/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:03:58 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/04 13:29:32 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa swap a: Intercambia los dos primeros elementos del stack a. 
No hace nada si hay uno o menos elementos.

sb swap b: Intercambia los dos primeros elementos del stack b. 
No hace nada si hay uno o menos elementos.

ss swap a y swap b a la vez. */

static void	swap(t_stack *stack)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	tmp->data = stack->top->data;
	tmp->next = stack->top->next->next;
	tmp->prev = stack->top->next;
	pop_first(stack);
	stack->top->next = tmp;
}

void	sa(t_program_data *pd, int print)
{
	if (pd->stack_a->top->next == NULL)
		return ;
	swap(pd->stack_a);
	if (print)
		ft_putstr("sa\n");
}

void	sb(t_program_data *pd, int print)
{
	if (pd->stack_b->top->next == NULL)
		return ;
	swap(pd->stack_b);
	if (print)
		ft_putstr("sb\n");
}

void	ss(t_program_data *pd, int print)
{
	if (pd->stack_a->top->next == NULL
		|| pd->stack_b->top->next == NULL)
		return ;
	swap(pd->stack_a);
	swap(pd->stack_b);
	if (print)
		ft_putstr("ss\n");
}
