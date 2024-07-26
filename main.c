/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:17:59 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/26 17:17:59 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_number(char *arg)
{
	int	i;

	i = 0;
	while (i < ft_strlen(arg))
	{
		if (i == 0)
		{
			if (arg[i] != '-' && !ft_isdigit(arg[i]))
				return (0);
		}
		else if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void	push(t_stack* stack, int data)
{
    t_node* new_node;
	
	new_node = (t_node*)malloc(sizeof(t_node));
    if (!new_node)
	{
        ft_putstr("Failed to allocate memory for new node\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    stack->top = new_node;
}

int	is_valid_and_push(char	*arg, t_stack *stack)
{
	long	num;

	if (is_number(arg))
	{
		num = ft_atoi(num);
		if (num <= INT_MAX && num >= INT_MIN)
		{
			push(stack, num);
			return (1);
		}
		else
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	else
		ft_putstr("Error\n");
	return (0);
}

int	has_duplicates(t_stack *s, int count)
{
	t_node	tmp;
	int		data;
	int		i;

	i = 1;
	while (i <= count)
	{
		tmp = s->top;
		data = tmp->data;
		tmp = tmp->next;
		if (tmp == NULL)
			return (0);
		if (data == tmp->data)
			return (1);
		i++;
	}
	return (0);
}

void	check_input(char	**args, int ac, t_stack *stack) // "1 3 40 -50 10"
{
	int	i;
	int	is_valid;

	i = 1;
	is_valid = 1;
	while (i < ac && is_valid)
	{
		is_valid = is_valid_and_push(args[1]);
		i++;
	}
	if (has_duplicates(stack, ac - 1))
		ft_putstr("Error\n");
	else
	{
		ft_putstr("valid input\n");
	}
}


int	main(int ac, char	**av)
{
	char	**args;
	t_stack	stack_a;

	if (ac > 1)
	{
		stack_a->top = NULL;
		if (ac == 2)
		{
			args = ft_split(av[1], ' ');
			check_input(args, ac, &stack_a);
		}
		else 
			check_input(av, ac, &stack_a);
	}
	if (args != NULL)
		free (args);
	return (0);
}