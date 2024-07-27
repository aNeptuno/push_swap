/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:49:10 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 22:03:39 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i = 1;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (i == 1 && arg[0] == '-')
		return (0);
	return (1);
}

static int	already_on_stack(int num, t_stack *s)
{
	t_node	*current;

	if (!s->top)
		return (0);
	current = s->top;
	while (current)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	is_valid_and_push(char	*arg, t_program_data *pd)
{
	long	num;

	if (is_number(arg))
	{
		num = ft_atoi(arg);
		if (num <= INT_MAX && num >= INT_MIN)
		{
			if (!already_on_stack(num, pd->stack_a))
			{
				push(pd->stack_a, num);
				pd->valid_input = 1;
			}
			else
				pd->valid_input = 0;
		}
		else
			pd->valid_input = 0;
	}
	else
		pd->valid_input = 0;
	if (!pd->valid_input)
		ft_putstr("Error\n");
}

static int	args_size(char **args)
{
	int	size;

	size = 0;
	while (args[size] != NULL)
		size++;
	return (size);
}

void	check_input(char	**args, int ac, t_program_data *pd)
{
	int	i;
	int	limit;

	limit = 1;
	i = ac - 1;
	if (pd->input_is_string)
	{
		limit = 0;
		i = args_size(args) - 1;
	}
	while (i >= limit && pd->valid_input)
	{
		is_valid_and_push(args[i], pd);
		i--;
	}
}
