/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_fmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:10:59 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/20 19:06:42 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

//Function prints a determined spacer for padding.
int	ft_print_spacer(const char *flags)
{
	int	count;

	count = 0;	
	if (zeropad(flags) == 1)
		count += ft_print_char('0');
	else if (blankpad(flags) == 1)
		count += ft_print_char(' ');
	return (count);
}

//Function works out the number of digits of an int.
static unsigned int int_digs(int num)
{
	unsigned int	digs;

	digs = 0;
	if (num == 0)
		digs++;
	if (num < 0)
	{
		digs++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		digs++;
	}
	return (digs);
}

//Function prints out a formatted integer based on format flags.
int	ft_print_int_fmt(int num, const char *flags)
{
	int	count;
	int width;
	int digs;
	
	digs = int_digs(num);
	width = flagwidth(flags);
	count = 0;
	if (plus(flags) == 1 && num > 0)
	{
		digs++;
		count += ft_print_char('+');
	}
	while (digs < width)
	{
		count += ft_print_spacer(flags);
		width--;
	}
	count += ft_print_int(num);
	return (count);
}

//Function prints out a formatted unsigned integer based on format flags.
int	ft_print_unsigned_fmt(unsigned int num, const char *flags)
{
	return (0);
}
