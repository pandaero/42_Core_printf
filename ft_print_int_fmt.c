/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_fmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:10:59 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 11:34:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_bonus.h"

//Function prints a determined spacer for padding.
static int	ft_print_int_spacer(const char *flags)
{
	int	count;

	count = 0;	
	if (zeropad(flags) == 1 && leftalign(flags) == 0)
		count += ft_print_char('0');
	else
		count += ft_print_char(' ');
	return (count);
}

//Function works out the number of digits of an int. Sign counts as digit.
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
	width = 0;
	if (width_checker(flags) == 1)
		width = width_reader(flags);
	count = 0;
	if (digs < width && leftalign(flags) == 0)
	{
		while (count < width - digs - plus(flags) - blankpad(flags))
			count += ft_print_int_spacer(flags);
	}
	if (num > 0)
	{
		if (plus(flags) == 1)
			count += ft_print_char('+');
		if (blankpad(flags) == 1)
			count += ft_print_char(' ');
	}
	if (precision_checker(flags) == 1 && leftalign(flags) == 0)
	{
		if (digs < precision_reader(flags))
		{
			while (count < precision_reader(flags) - digs)
				count += ft_print_int_spacer(flags);
		}
	}
	count += ft_print_int(num);
	if (digs < width && leftalign(flags) == 1)
	{
		while (count < width)
			count += ft_print_int_spacer(flags);
	}
	return (count);
}

//Function prints out a formatted unsigned integer based on format flags.
int	ft_print_unsigned_fmt(unsigned int num, const char *flags)
{
	return (0);
}

/*Test
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	int		count;
	char	*flags1 = strdup("%010.8d");
	char	*flags2 = strdup("%+20.5i");
	char	*flags3 = strdup("%-10d");
	char	*flags4 = strdup("%.10d");
	char	*flags5 = strdup("%- 20.10d");
	int		num = 1435234;

	count = 0;
	count = ft_print_int_fmt(num, flags1);
	printf("\n");
	printf("Printed: %d, Flags: %s\n", count, flags1);
	count = ft_print_int_fmt(num, flags2);
	printf("\n");
	printf("Printed: %d, Flags: %s\n", count, flags2);
	count = ft_print_int_fmt(num, flags3);
	printf("\n");
	printf("Printed: %d, Flags: %s\n", count, flags3);
	count = ft_print_int_fmt(num, flags4);
	printf("\n");
	printf("Printed: %d, Flags: %s\n", count, flags4);
	count = ft_print_int_fmt(num, flags5);
	printf("\n");
	printf("Printed: %d, Flags: %s\n", count, flags5);
	free(flags1);
	free(flags2);
	free(flags3);
	free(flags4);
	free(flags5);
	return (0);
}
//*/