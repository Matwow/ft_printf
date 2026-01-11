# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroard <maroard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 21:13:43 by maroard           #+#    #+#              #
#    Updated: 2026/01/02 18:21:54 by maroard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR			= ar rcs
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I. -Ift_printf
RM			= rm -f
NAME		= libft.a

SRC_BONUS	= $(wildcard *_bonus.c)
OBJ_BONUS	= $(SRC_B:.c=.o)

SRC_ALL		= $(wildcard *.c)
SRC			= $(filter-out $(SRC_BONUS),$(SRC_ALL))
OBJ			= $(SRC:.c=.o)

SRC_PRINTF	= $(wildcard ft_printf/*.c) $(wildcard ft_printf_fd/*.c)
OBJ_PRINTF	= $(SRC_PRINTF:.c=.o)

ALL_OBJ		= $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF)

all: $(NAME)

$(NAME): $(ALL_OBJ)
	$(AR) $(NAME) $(ALL_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS) $(OBJ_PRINTF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re