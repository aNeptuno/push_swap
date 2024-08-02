/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:04:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/02 15:31:57 by adiban-i         ###   ########.fr       */
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
	t_node	*last;
	t_node	*second_last;

	last = stack->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	last->prev = NULL;
	stack->top->prev = last;
	stack->top = last;
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
