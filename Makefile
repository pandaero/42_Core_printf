# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:13:17 by pandalaf          #+#    #+#              #
#    Updated: 2022/10/14 23:46:35 by pandalaf         ###   ########.fr        #
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
		ft_print_hex.c ft_print_char.c ft_print_str.c ft_print_ptr.c
# Object files
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# Operating system differences, special sources
OS = $(shell uname)
#ifeq ($(OS), Darwin)
	CFLAGS += -D MACOS
#endif

# Make desired targets
all: directories $(NAME)

# Make required directories
directories: $(OBJ_DIR)

# Make target archive
$(NAME): $(OBJS) $(addprefix $(LIBFT_PATH), $(LIBFT))
	ar -rcs $@ $^

# Make Libft archive
$(addprefix $(LIBFT_PATH), $(LIBFT)): $(LIBFT_PATH)
	make -C $(LIBFT_PATH) all

# Make object files
$(addprefix $(OBJ_DIR), %.o): %.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $^ -o $@

# Make object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean intermediary files
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_PATH) clean

# Clean all non-source files
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Wipe all and make again
re: fclean all

# Make sure these aren't treated as files
.PHONY: all clean fclean re bonus directories
