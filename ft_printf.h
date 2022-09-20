/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:30:39 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/20 14:30:59 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>

//Function prints out a formatted string based on inputs. Returns written chars.
int		ft_printf(const char *format, ...);
//Function prints out a character to the standard output. Returns written count.
int		ft_print_char(char ch);
//Helpers
//Function identifies the format types. Returns 1 or 0.
int		types(char ch);
//Function reads variable type after a determined starting location.
char	typeread(const char *string, int start);
//Function reads format flags after a determined starting location.
char	*flagread(const char * string, int start);
#endif