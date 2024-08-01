# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 20:06:04 by adiban-i          #+#    #+#              #
#    Updated: 2024/08/01 12:02:40 by adiban-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -g -O2 #-Werror
HEADERS = -I ./includes

# DIRECTORIES
SRC_DIR = src
LIBFT_DIR = libft_functions
COMM_DIR = commands
ALGO_DIR = algorithm

# SOURCE FILES
SRC_FILES = $(LIBFT_DIR)/ft_split.c \
			$(LIBFT_DIR)/libft.c \
			$(LIBFT_DIR)/ft_atoi.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/free_data.c \
			$(SRC_DIR)/helpers.c \
			$(SRC_DIR)/stack_ops.c \
			$(SRC_DIR)/input_validation.c \
			$(COMM_DIR)/push.c \
			$(COMM_DIR)/reverse_rotate.c \
			$(COMM_DIR)/rotate.c \
			$(COMM_DIR)/swap.c  \
			$(ALGO_DIR)/small_sort.c  \
			$(ALGO_DIR)/push_swap.c  \
			$(ALGO_DIR)/set_initial_data.c  \
			$(ALGO_DIR)/algorithm_utils.c  \

# OBJECT FILES
OBJS = $(SRC_FILES:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
