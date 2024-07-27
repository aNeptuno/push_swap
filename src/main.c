/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:17:59 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/27 20:27:17 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_program_data(t_program_data *prog_data)
{
	prog_data->stack_a = malloc(sizeof(t_stack));
	prog_data->stack_b = malloc(sizeof(t_stack));
	if (prog_data->stack_a == NULL || prog_data->stack_b == NULL)
		return ;
	prog_data->stack_a->top = NULL;
	prog_data->stack_b->top = NULL;
	prog_data->valid_input = 1;
	prog_data->input_is_string = 0;
}

int	main(int ac, char	**av)
{
	char			**args;
	t_program_data	prog_data;

	if (ac > 1)
	{
		init_program_data(&prog_data);
		if (ac == 2 && ft_strchr(av[1], ' ') != NULL)
		{
			prog_data.input_is_string = 1;
			args = ft_split(av[1], ' ');
			check_input(args, ac, &prog_data);
			free (args);
		}
		else
			check_input(av, ac, &prog_data);
		free_data(&prog_data);
	}
	return (0);
}