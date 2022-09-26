# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:13:17 by pandalaf          #+#    #+#              #
#    Updated: 2022/09/26 12:17:36 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := gcc
CFLAGS := -Wall -Werror -Wextra
LIBFT_PATH := libft/
LIBFT = $(LIBFT_PATH)/libft.a
SRCS := ft_printf.c type_reader.c flag_reader.c ft_print_int.c ft_print_str.c\
		ft_print_unsigned.c	ft_print_hex.c ft_print_ptr.c ft_print_char.c\
		spec_reader.c padding.c ft_print_int_fmt.c ft_print_str_fmt.c\
		ft_print_hex_fmt.c ft_print_ptr_fmt.c flag_types.c
		
BSRCS :=  
OBJ_DIR := obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BOBJS = $(addprefix $(OBJ_DIR), $(BSRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $@ $^

$(LIBFT): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) all

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