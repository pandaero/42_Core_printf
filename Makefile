# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:13:17 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/09 12:25:51 by pandalaf         ###   ########.fr        #
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
# Object files
OBJS = $(SRCS:.c=.o) ft_print_ptr.o

# Operating system differences, special sources
OS = $(shell uname)
ifeq ($(OS), Darwin)
	SSRCS = ft_print_ptr_macos.c
else
	SSRCS = ft_print_ptr_linux.c
endif

# Make desired targets
all: $(NAME)

# Make archive
$(NAME): $(OBJS) $(addprefix $(LIBFT_PATH), $(LIBFT))
	ar -rcs $@ $^

# Make Libft archive
$(addprefix $(LIBFT_PATH), $(LIBFT)): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) all

# Clean intermediary files
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

# Clean all non-source files
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Wipe all and make again
re: fclean all

# Make object files
%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

# Make specific object file
ft_print_ptr.o: $(SSRCS)
	$(CC) -c $(CFLAGS) $^ -o $@

# Make sure these aren't treated as files
.PHONY: all clean fclean re bonus
