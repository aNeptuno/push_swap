/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3034/08/01 13:10:17 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/04 14:54:00 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

static void	do_command(char	*command, t_program_data *pd)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(pd, 1, 0);
	else if (!ft_strcmp(command, "pb\n"))
		pb(pd, 1, 0);
	else if (!ft_strcmp(command, "sa\n"))
		sa(pd, 0);
	else if (!ft_strcmp(command, "sb\n"))
		sb(pd, 0);
	else if (!ft_strcmp(command, "ss\n"))
		ss(pd, 0);
	else if (!ft_strcmp(command, "ra\n"))
		ra(pd, 0);
	else if (!ft_strcmp(command, "rb\n"))
		rb(pd, 0);
	else if (!ft_strcmp(command, "rr\n"))
		rr(pd, 0);
	else if (!ft_strcmp(command, "rra\n"))
		rra(pd, 0);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(pd, 0);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(pd, 0);
	else
		ft_putstr("Error\n");
}

static void	print_result(int is_sorted, int commands_count, int stack_size)
{
	ft_putstr("Stack size: ");
	ft_putstr(ft_itoa(stack_size));
	ft_putstr("   |   Number of commands: ");
	ft_putstr(ft_itoa(commands_count));
	ft_putstr("\n");
	if (is_sorted)
	{
		printf("\033[0;32m");
		ft_putstr("OK\n");
		printf("\033[0m");
	}
	else
	{
		printf("\033[0;31m");
		ft_putstr("KO\n");
		printf("\033[0m");
	}
}

static void	init_stack(int ac, char **av, t_program_data *pd)
{
	char	**args;

	if (ac == 2 && ft_strchr(av[1], ' ') != NULL)
	{
		pd->input_is_string = 1;
		args = ft_split(av[1], ' ');
		check_input(args, ac, pd);
		free_args(args);
	}
	else
		check_input(av, ac, pd);
}

int	main(int ac, char	**av)
{
	char			*command;
	int				commands_count;
	t_program_data	pd;

	if (ac == 1)
		return (0);
	init_program_data(&pd);
	init_stack(ac, av, &pd);
	command = get_next_line(STDIN_FILENO);
	commands_count = 1;
	while (command != NULL)
	{
		do_command(command, &pd);
		command = get_next_line(STDIN_FILENO);
		commands_count++;
	}
	print_result(is_stack_sorted(pd.stack_a),
		commands_count, stack_len(pd.stack_a->top));
	free_data(&pd);
	return (0);
}
