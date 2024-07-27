/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:04:19 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 21:05:53 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.

pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
*/

static void push_command(t_stack *src_stack, t_stack *dest_stack)
{
	push(dest_stack, src_stack->top->data);
	pop_first(src_stack);
}

void pa(t_program_data *pd)
{
	if (pd->stack_b->top == NULL)
		return ;
	push_command(pd->stack_b, pd->stack_a);
	ft_putstr("pa\n");
}

void pb(t_program_data *pd)
{
	if (pd->stack_a->top == NULL)
		return ;
	push_command(pd->stack_a, pd->stack_b);
	ft_putstr("pb\n");
}
