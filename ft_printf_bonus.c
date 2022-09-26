/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:14:25 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 07:15:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_bonus.h"

//Function passes flags to format printers for writing to standard output.
static int	converter_fmt(va_list args, char type, const char *flags)
{
	int	count;

	count = 0;
	if (type == 'd' || type == 'i')
		count = ft_print_int_fmt(va_arg(args, int), flags);
	else if (type == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (type == 's')
		count = ft_print_str_fmt(va_arg(args, char *), flags);
	else if (type == 'u')
		count = ft_print_unsigned_fmt(va_arg(args, unsigned int), flags);
	else if (type == 'p')
		count = ft_print_ptr_fmt(va_arg(args, void *), flags);
	else if (type == 'x')
		count = ft_print_hex_fmt(va_arg(args, unsigned int), flags, 1);
	else if (type == 'X')
		count = ft_print_hex_fmt(va_arg(args, unsigned int), flags, 0);
	return (count);
}

//Function calls standard printers for writing to standard output.
static int	converter(va_list args, char type)
{
	int	count;

	count = 0;
	if (type == 'd' || type == 'i')
		count = ft_print_int(va_arg(args, int));
	else if (type == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (type == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (type == 'u')
		count = ft_print_unsigned(va_arg(args, unsigned int));
	else if (type == 'p')
		count = ft_print_ptr(va_arg(args, void *));
	else if (type == 'x')
		count = ft_print_hex(va_arg(args, unsigned int), 1);
	else if (type == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), 0);
	return (count);
}

//Function reads and passes specifier flags to converter.
static int	interpreter(va_list args, int start, const char *format)
{
	char	type;
	char	*flags;
	int		count;

	count = 0;
	if (format[start + 1] == '%')
	{
		count += ft_print_char('%');
		return (count);
	}
	flags = flag_reader(format, start);
	type = type_reader(format, start);
	if (flags[0] == '\0')
		count += converter(args, type);
	else
		count += converter_fmt(args, type, flags);
	free(flags);
	return (count);
}

//Function writes out input-based formatted string. Returns written char count.
int	ft_printf_bonus(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	char	*flags;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += interpreter(args, i, format);
			flags = flag_reader(format, i);
			i += ft_strlen(flags) + 1;
			free(flags);
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
