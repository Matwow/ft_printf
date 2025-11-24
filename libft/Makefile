# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroard <maroard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 21:13:43 by maroard           #+#    #+#              #
#    Updated: 2025/11/24 11:31:34 by maroard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR          = ar rcs
NAME        = libft.a
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

SRC_BONUS   = $(wildcard *bonus.c)
SRC         = $(filter-out $(SRC_BONUS),  $(wildcard *.c))

OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
