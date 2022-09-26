/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:30:39 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 11:58:11 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

//Function prints out a formatted string based on inputs. Returns written chars.
int				ft_printf(const char *format, ...);
//Function prints out a character to the standard output. Returns written count.
int				ft_print_char(char ch);
//Function prints an integer to standard output, unformatted. Returns written.
int				ft_print_int(int num);
//Function prints an unsigned integer to standard output, unformatted.
int				ft_print_unsigned(unsigned int num);
//Function prints out a hexadecimal number to the standard output. Case option.
int				ft_print_hex(unsigned int num, int cas);
//Function prints out a hexadecimal number to the standard output. Case option.
int				ft_print_hex_long(unsigned long long num, int cas);
//Function prints an pointer address to standard output, unformatted.
int				ft_print_ptr(void *ptr);
//Function prints a char string to standard output, unformatted.
int				ft_print_str(const char *str);
//Function prints a hexadecimal prefix to the standard output.
int				hex_prefix_printer(int cas);
//Function prints out a formatted integer based on format flags.
int				ft_print_int_fmt(int num, const char *flags);
//Function prints out a formatted unsigned integer based on format flags.
int				ft_print_unsigned_fmt(unsigned int num, const char *flags);
//Function prints out a formatted hexadecimal number. Returns written count.
int				ft_print_hex_fmt(unsigned int num, const char *flags, int cas);
//Functions prints out a string to the standard output based on format flags.
int				ft_print_str_fmt(const char *str, const char *flags);
//Function prints out a formatted pointer address.
int				ft_print_ptr_fmt(void *ptr, const char *flags);
//Function identifies the format types. Returns 1 or 0.
int				type_checker(char ch);
//Function reads a type specifier after a determined starting location.
char			type_reader(const char *string, int start);
//Function identifies a character as a format flag type. Returns 1 or 0.
int				flag_checker(char ch);
//Function reads format flags after a determined starting location. Alloc's str.
char			*flag_reader(const char * string, int start);
//Function determines whether a width specification is present.
int				width_checker(const char *flags);
//Function works out the minimum width parameter from a format flag specifier.
unsigned int 	width_reader(const char *flags);
//Function returns whether precision flag is called.
int				precision_checker(const char *flags);
//Function determines the precision value. Flags must contain precision flag.
unsigned int	precision_reader(const char *flags);
//Function returns whether zero padding flag is called.
int				zeropad(const char *flags);
//Function determines whether blank padding flag is called.
int				blankpad(const char *flags);
//Function returns whether left align flag is called.
int				leftalign(const char *flags);
//Function determines whether hex prefix flag is called.
int				hexpre(const char *flags);
//Function determines whether plus sign flag is called.
int				plus(const char *flags);
#endif