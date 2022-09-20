/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:13:51 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/20 16:01:55 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

//Function interprets specified format flags and type. Passes them for writing.
int	converter(va_list args, char type, const char *flags)
{
	int	count;

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

//Function passes specifier flags to output functions based on type.
int	interpreter(va_list args, int start, const char *format)
{
	char	type;
	char	*flags;
	int		count;

	count = 0;
	if (type == '%')
	{
		count += ft_print_char('%');
		return (count);
	}
	flags = flagread(format, start);
	type = typeread(format, start);
	count += converter(args, type, flags);
	free(flags);
	return (count);
}

//Function writes out input-based formatted string. Returns written char count.
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += interpreter(args, i, format);
			i += ft_strlen(flagread(format, i)) + 1;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
