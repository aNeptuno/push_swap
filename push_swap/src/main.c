/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:17:59 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/04 14:28:32 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char	**av)
{
	char			**args;
	t_program_data	prog_data;

	if (ac == 1)
		return (0);
	init_program_data(&prog_data);
	if (ac == 2 && ft_strchr(av[1], ' ') != NULL)
	{
		prog_data.input_is_string = 1;
		args = ft_split(av[1], ' ');
		check_input(args, ac, &prog_data);
		free_args(args);
	}
	else
		check_input(av, ac, &prog_data);
	if (prog_data.valid_input && !is_stack_sorted(prog_data.stack_a))
	{
		if (prog_data.stack_a->size <= 3)
			small_sort(prog_data.stack_a, &prog_data);
		else
			push_swap(prog_data.stack_a, prog_data.stack_b, &prog_data);
	}
	free_data(&prog_data);
	return (0);
}
