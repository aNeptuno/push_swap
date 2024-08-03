# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 13:03:06 by adiban-i          #+#    #+#              #
#    Updated: 2024/08/03 14:25:39 by adiban-i         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -O2 -g #-Werror
HEADERS = -I. -I../push_swap/includes
PS_DIR = ../push_swap
PUSH_SWAP_LIB = $(PS_DIR)/push_swap.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PUSH_SWAP_LIB):
	@echo $(CYAN)Building push_swap library...$(NC)
	@$(MAKE) -C $(PS_DIR) all_bonus

$(NAME): $(OBJS) $(PUSH_SWAP_LIB)
	$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(PUSH_SWAP_LIB) -o $(NAME)
	@echo $(GREEN)Compilation of [$(NAME)] is successful 🎉$(NC)

%.o: %.c
	@echo $(MAGENTA)Compiling [$<]...$(NC)
	$(CC) -c $(CFLAGS) $(HEADERS) $< -o $@
	@printf $(UP)$(CUT)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(PS_DIR) clean
	@echo $(RED)Cleaned [$(OBJS)]$(NC)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(PS_DIR) fclean
	@echo $(RED)Cleaned [$(NAME)]$(NC)

re: fclean all

.PHONY: all clean fclean re