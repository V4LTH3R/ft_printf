# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: v4lth3r <v4lth3r@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/09 15:43:24 by v4lth3r          #+#    #+#              #
#    Updated: 2026/11/09 15:43:28 by v4lth3r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
SRC = ft_printf.c ft_utils.c
OBJS = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<	

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
