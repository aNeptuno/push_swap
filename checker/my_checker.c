/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:10:17 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/03 14:42:26 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_checker.h"

void	init_data(t_program_data *pd)
{
	pd->stack_a = malloc(sizeof(t_stack));
	if (pd->stack_a == NULL)
		return ;
	pd->stack_a->top = NULL;
	pd->stack_a->size = 0;
	pd->valid_input = 1;
	pd->input_is_string = 0;
}
int	main(int ac, char	**av)
{
	//char			**commands;
	char			**args;
	t_program_data	pd;

	if (ac == 1)
		return (0);
	init_data(&pd);
	if (ac == 2 && ft_strchr(av[1], ' ') != NULL)
	{
		pd.input_is_string = 1;
		args = ft_split(av[1], ' ');
		check_input(args, ac, &pd);
		free_args(args);
	}
	else
		check_input(av, ac, &pd);

	printf("Argument count: %d\n", ac - 1);
	for (int i = 1; i < ac; i++) {
		printf("Argument %d: %s\n", i, av[i]);
	}

	// Luego, procesamos los movimientos desde la entrada estándar
	char command[4]; // Máximo tamaño de comando es 3 caracteres + terminador nulo
	while (scanf("%3s", command) != EOF) {
		printf("Command: %s\n", command);
		// Aquí procesarías cada comando
	}
	return (0);

}