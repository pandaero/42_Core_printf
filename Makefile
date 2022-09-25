# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:13:17 by pandalaf          #+#    #+#              #
#    Updated: 2022/09/25 10:02:35 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Werror -Wextra
SRCS := ft_printf.c
BSRCS := 
OBJ_DIR := obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BOBJS = $(addprefix $(OBJ_DIR), $(BSRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(OBJS) $(BOBJS)
	ar rcs $(NAME) $^

clean:
	rm -fr $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(addprefix $(OBJ_DIR), %.o): %.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: all clean fclean re bonus