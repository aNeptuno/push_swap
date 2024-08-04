# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 13:03:06 by adiban-i          #+#    #+#              #
#    Updated: 2024/08/04 15:02:09 by adiban-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
BLACK = "\033[0;30m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
MAGENTA = "\033[0;35m"
CYAN = "\033[0;36m"
WHITE = "\033[0;37m"
NC = "\033[0;0m"  # NO COLOR
UP = "\033[A"
CUT = "\033[K"

# RULES
NAME = my_checker
CC = gcc
CFLAGS = -Wall -Wextra -O2 -g -Werror
HEADERS = -I.
PUSH_SWAP_LIB = ../push_swap/push_swap.a

SRCS = my_checker.c get_next_line.c get_next_line_utils.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PUSH_SWAP_LIB):
	@echo $(CYAN)Building push_swap library...$(NC)
	cd ../push_swap && make

$(NAME): $(OBJS) $(PUSH_SWAP_LIB)
	$(CC) $(CFLAGS) $(HEADERS) $^ -o $(NAME)
	cp $(NAME) ../push_swap 
	@echo $(GREEN)Compilation of [$(NAME)] is successful 🎉$(NC)

%.o: %.c
	@echo $(MAGENTA)Compiling [$<]...$(NC)
	$(CC) -c $(CFLAGS) $(HEADERS) $< -o $@

clean:
	rm -f $(OBJS)
	@echo $(RED)Cleaned [$(OBJS)]$(NC)

fclean: clean
	rm -f $(NAME)
	cd ../push_swap && rm -f $(NAME)
	@echo $(RED)Cleaned [$(NAME)]$(NC)

re: fclean all

.PHONY: all clean fclean re