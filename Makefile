# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroard <maroard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 18:14:48 by maroard           #+#    #+#              #
#    Updated: 2025/11/24 18:32:18 by maroard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR          = ar rcs
NAME        = libftprintf.a
CC          = gcc
CFLAGS      = -Wall -Wextra #-Werror
RM          = rm -f

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC         = $(wildcard *.c)
OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
