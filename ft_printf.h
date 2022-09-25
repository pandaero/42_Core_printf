/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:30:39 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/25 09:43:11 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

//Function prints out a formatted string based on inputs. Returns written chars.
int		ft_printf(const char *format, ...);
//Function prints out an integer to the standard output.
int		ft_print_int(int num);
//Function prints out a formatted integer based on format flags.
int		ft_print_int_fmt(int num, const char *flags);
//Function prints out a formatted unsigned integer based on format flags.
int		ft_print_unsigned_fmt(unsigned int num, const char *flags);
//Function prints out a formatted hexadecimal number. Returns written count.
int		ft_print_hex_fmt(unsigned int num, const char *flags, int cas);
//Function prints out a character to the standard output. Returns written count.
int		ft_print_char(char ch);
//Functions prints out a string to the standard output based on format flags.
int		ft_print_str_fmt(const char *str, const char *flags);
//Function prints out a formatted pointer address.
int		ft_print_ptr_fmt(void *ptr, const char *flags);
//Function identifies the format types. Returns 1 or 0.
int		types(char ch);
//Function identifies a character as a format flag type. Returns 1 or 0.
int		flagtypes(char ch);
//Function returns whether left align flag is called.
int		leftalign(const char *flags);
//Function returns whether zero padding flag is called.
int		zeropad(const char *flags);
//Function returns whether precision flag is called.
int		precision(const char *flags);
//Function determines whether hex prefix flag is called.
int		hexpre(const char *flags);
//Function determines whether blank padding flag is called.
int		blankpad(const char *flags);
//Function determines whether plus sign flag is called.
int		plus(const char *flags);
//Function works out the minimum width parameter from a format flag specifier.
int 	flagwidth(const char *flags);
//Function reads a format variable type after a determined starting location.
char	typeread(const char *string, int start);
//Function reads format flags after a determined starting location. Alloc's str.
char	*flagread(const char *string, int start);
#endif