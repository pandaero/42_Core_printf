# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:13:17 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/08 20:39:49 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
LIBFT := libft.a
LIBFT_PATH := libft/
CC := cc
CFLAGS := -Wall -Werror -Wextra
SRCS := ft_printf.c type_reader.c ft_print_int.c ft_print_unsigned.c\
		ft_print_hex.c ft_print_ptr.c ft_print_char.c ft_print_str.c
OBJ_DIR := obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(addprefix $(LIBFT_PATH), $(LIBFT))
	ar -rcs $@ $^

$(addprefix $(LIBFT_PATH), $(LIBFT)): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) all

clean:
	rm -fr $(OBJ_DIR)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

$(addprefix $(OBJ_DIR), %.o): %.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: all clean fclean re bonus