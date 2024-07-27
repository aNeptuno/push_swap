/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:04:26 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 21:55:17 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra rotate a: 
Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.

rb rotate b: 
Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.

rr ra y rb al mismo tiempo.

*/

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->top;
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	stack->top = first->next;
	stack->top->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
}

void	ra(t_program_data *pd)
{
	if (pd->stack_a->top == NULL)
		return ;
	if (pd->stack_a->top->next == NULL)
		return ;
	rotate(pd->stack_a);
	ft_putstr("ra\n");
}

void	rb(t_program_data *pd)
{
	if (pd->stack_b->top == NULL)
		return ;
	if (pd->stack_b->top->next == NULL)
		return ;
	rotate(pd->stack_b);
	ft_putstr("rb\n");
}

void	rr(t_program_data *pd)
{
	if (pd->stack_a->top == NULL
		|| pd->stack_b->top == NULL)
		return ;
	if (pd->stack_a->top->next == NULL
		|| pd->stack_b->top->next == NULL)
		return ;
	rotate(pd->stack_a);
	rotate(pd->stack_b);
	ft_putstr("rr\n");
}
