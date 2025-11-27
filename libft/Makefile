# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroard <maroard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 21:13:43 by maroard           #+#    #+#              #
#    Updated: 2025/11/21 11:28:10 by maroard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR      = ar rcs
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

NAME    = libft.a

SRC_B   = $(wildcard *_bonus.c)
OBJ_B   = $(SRC_B:.c=.o)

SRC     = $(wildcard *.c)
SRC     := $(filter-out *$(SRC_B),$(SRC))
OBJ     = $(SRC:.c=.o)

ALL_OBJ = $(OBJ) $(OBJ_B)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

bonus: $(OBJ_B)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
