/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:12:34 by adiban-i          #+#    #+#             */
/*   Updated: 2024/08/04 14:56:10 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_CHECKER_H
# define MY_CHECKER_H

# include "../push_swap/includes/push_swap.h"

# define BUFFER_SIZE 4
# include <fcntl.h>
# include <string.h>

// Utils
int		ft_strcmp(char *str1, char *str2);
void	init_program_data(t_program_data *prog_data);
int		stack_len(t_node *stack);

// Get next line
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_calloc(size_t number, size_t size);
void	*ft_memset(void *dst, int c, size_t len);

#endif