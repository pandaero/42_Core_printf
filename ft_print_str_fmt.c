/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_fmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:06:15 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 12:19:42 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "ft_printf.h"

//Function prints spacing for the string width and precision specifications.
static int	print_str_spacer(const char *str, unsigned int wide, int max)
{
	int	count;

	count = 0;
	if (ft_strlen(str) < wide)
	{
		while (count < (int) wide - (int) ft_strlen(str))
			count += write(1, " ", 1);
	}
	if (max < (int) wide)
	{
		while (count < (int) wide - max)
			count += write(1, " ", 1);
	}
	return (count);
}

//Functions prints out a string to the standard output based on format flags.
int	ft_print_str_fmt(const char *str, const char *flags)
{
	unsigned int	count;
	int				max;
	unsigned int	wide;
	unsigned int	i;

	max = INT_MAX;
	wide = 0;
	if (precision_checker(flags) == 1)
		max = (int) precision_reader(flags);
	if (width_checker(flags) == 1)
		wide = width_reader(flags);
	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	if (leftalign(flags) == 0)
		count += print_str_spacer(str, wide, max);
	i = 0;
	while (str[i] != '\0' && i < (unsigned int) max)
	{
		count += write(1, &str[i], 1);
		i++;
	}
	if (leftalign(flags) == 1)
		count += print_str_spacer(str, wide, max);
	return (count);
}

/*Test
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	s[] = "Hello, how are you today?";
	char	*flags1 = strdup("%10.8s");
	char	*flags2 = strdup("%20.5s");
	char	*flags3 = strdup("%10s");
	char	*flags4 = strdup("%.10s");
	char	*flags5 = strdup("%-20.10s");
	int		count;

	count = 0;
	count = ft_print_str_fmt(s, flags1);
	printf("\n");
	printf("Printed: %d, Flags: %s\n", count, flags1);
	count = ft_print_str_fmt(s, flags2);
	printf("\n");
	printf("Printed: %d, Flags: %s\n", count, flags2);
	count = ft_print_str_fmt(s, flags3);
	printf("\n");
	printf("Printed: %d, Flags: %s\n", count, flags3);
	count = ft_print_str_fmt(s, flags4);
	printf("\n");
	printf("Printed: %d, Flags: %s\n", count, flags4);
	count = ft_print_str_fmt(s, flags5);
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