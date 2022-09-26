/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 06:28:08 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 08:07:44 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//Function determines whether a width specification is present.
int	width_checker(const char *flags)
{
	int	i;

	i = 0;
	while (flag_checker(flags[i]) == 1)
		i++;
	if (flags[i] >= '1' && flags[i] <= '9')
		return (1);
	return (0);
}

//Function returns whether precision flag is called.
int	precision_checker(const char *flags)
{
	int	i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

//Function works out the minimum width parameter from a format flag specifier.
unsigned int	width_reader(const char *flags)
{
	unsigned int	i;
	unsigned int	width;

	i = 0;
	while (flag_checker(flags[i]) == 1)
		i++;
	width = 0;
	while (ft_isdigit(flags[i]) == 1)
	{
		width = width * 10 + (flags[i] - '0');
		i++;
	}
	return (width);
}

//Function determines the precision value. Flags must contain precision flag.
unsigned int	precision_reader(const char *flags)
{
	int	i;
	int	prec;

	i = 0;
	while (flags[i] != '.')
		i++;
	prec = 0;
	while (type_checker(flags[i + 1]) == 0)
	{
		prec = prec * 10 + (flags[i + 1] - '0');
		i++;
	}
	return (prec);
}
