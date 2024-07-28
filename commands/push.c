/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:04:19 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/28 13:31:54 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.

pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
*/

static void	push_command(t_stack *src_stack, t_stack *dest_stack)
{
	push(dest_stack, src_stack->top->data);
	pop_first(src_stack);
}

/// @brief Push into a first element of b
/// @param repeat times to exec the function
void	pa(t_program_data *pd, int repeat)
{
	if (pd->stack_b->top == NULL)
		return ;
	push_command(pd->stack_b, pd->stack_a);
	ft_putstr("pa\n");
	if (repeat > 1)
		pa(pd, repeat - 1);
}

/// @brief Push into b first element of a
/// @param repeat times to exec the function
void	pb(t_program_data *pd, int repeat)
{
	if (pd->stack_a->top == NULL)
		return ;
	push_command(pd->stack_a, pd->stack_b);
	ft_putstr("pb\n");
	if (repeat > 1)
		pb(pd, repeat - 1);
}
