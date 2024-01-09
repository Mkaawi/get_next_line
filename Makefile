# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdennac <abdennac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 22:31:15 by abdennac          #+#    #+#              #
#    Updated: 2024/01/09 18:24:13 by abdennac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c main.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c get_next_line.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -rcs $@ $^

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	
re : fclean all