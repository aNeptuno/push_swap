/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:20:15 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/26 17:20:15 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

// Definir el nodo de la lista enlazada
typedef struct s_node
{
    int data;
    struct s_node* next;
}	t_node;

// Definir la pila (stack)
typedef struct s_stack
{
    t_node* top;
}	t_stack;

// Libft functions
int     ft_isdigit(int c);
void	ft_putstr(char *s);
int     ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
#endif