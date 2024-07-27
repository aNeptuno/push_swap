/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:04:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 21:54:37 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rra reverse rotate a: 
Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.

rrb reverse rotate b: 
Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.

rrr rra y rrb al mismo tiempo. */

static void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->top;
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	stack->top = last;
	first->prev = last;
}

void	rra(t_program_data *pd)
{
	if (pd->stack_a->top == NULL)
		return ;
	if (pd->stack_a->top->next == NULL)
		return ;
	reverse_rotate(pd->stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_program_data *pd)
{
	if (pd->stack_b->top == NULL)
		return ;
	if (pd->stack_b->top->next == NULL)
		return ;
	reverse_rotate(pd->stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_program_data *pd)
{
	if (pd->stack_a->top == NULL
		|| pd->stack_b->top == NULL)
		return ;
	if (pd->stack_a->top->next == NULL
		|| pd->stack_b->top->next == NULL)
		return ;
	reverse_rotate(pd->stack_a);
	reverse_rotate(pd->stack_b);
	ft_putstr("rrr\n");
}
