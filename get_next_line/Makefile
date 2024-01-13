# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 22:31:15 by abdennac          #+#    #+#              #
#    Updated: 2024/01/11 19:25:22 by abdennac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = get_next_line.c get_next_line_utils.c main.c
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
OBJ = $(SRC:.c=.o)

all: $(NAME) run

%.o: %.c get_next_line.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

run:
	@./$(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all run clean fclean re
