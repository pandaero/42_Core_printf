# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:13:17 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/08 21:01:52 by pandalaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME := libftprintf.a
# Compiler options
CC := cc
CFLAGS := -Wall -Werror -Wextra
# Libft location
LIBFT := libft.a
LIBFT_PATH := libft/
# Unconditionally included source files
SRCS := ft_printf.c type_reader.c ft_print_int.c ft_print_unsigned.c \
		ft_print_hex.c ft_print_char.c ft_print_str.c
# Operating system differences
OS = $(shell uname)
ifeq ($(OS), Linux)
	SRCS += ft_print_ptr_linux.c
endif
ifeq ($(OS), Darwin)
	SRCS += ft_print_ptr_macos.C
endif
# Object files
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(addprefix $(LIBFT_PATH), $(LIBFT))
	ar -rcs $@ $^

$(addprefix $(LIBFT_PATH), $(LIBFT)): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) all

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

.PHONY: all clean fclean re bonus