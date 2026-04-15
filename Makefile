# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 10:18:28 by mde-nas           #+#    #+#              #
#    Updated: 2026/04/15 10:35:20 by mde-nas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= snake

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

SRCS	= main.c snake.c render.c input.c terminal.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
