/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:30:39 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/25 14:22:55 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

//Function prints out a formatted string based on inputs. Returns written chars.
int		ft_printf(const char *format, ...);
//Function prints out a character to the standard output. Returns written count.
int		ft_print_char(char ch);
//Function prints an integer to standard output, unformatted. Returns written.
int		ft_print_int(int num);
//Function prints an unsigned integer to standard output, unformatted.
int		ft_print_unsigned(unsigned int num);
//Function prints out a hexadecimal number to the standard output. Case option.
int		ft_print_hex(unsigned int num, int cas);
//Function prints out a hexadecimal number to the standard output. Case option.
int		ft_print_hex_long(unsigned long long num, int cas);
//Function prints an pointer address to standard output, unformatted.
int		ft_print_ptr(void *ptr);
//Function prints a char string to standard output, unformatted.
int		ft_print_str(const char *str);
//Function prints a hexadecimal prefix to the standard output.
int		hex_prefix_printer(int cas);
//Function identifies the format types. Returns 1 or 0.
int		types(char ch);
//Function reads a format variable type after a determined starting location.
char	typeread(const char *string, int start);
#endif