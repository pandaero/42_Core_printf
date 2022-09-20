/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_interpreter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:00:50 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/20 17:35:42 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Function identifies a character as a format flag type. Returns 1 or 0.
int	flagtypes(char ch)
{
	if (ch == '-' || ch == '0' || ch == '.')
		return (1);
	else if (ch == '#' || ch == ' ' || ch == '+')
		return (1);
	else
		return (0);
}

//Function returns the types present in the format flag specifier.
char flagtype(const char *flags)
{
	if (flagtypes(flags[0]) == 1)
		return (flags[0]);
}

//Function works out the minimum width parameter from a format flag specifier.
int flagwidth(const char *flags)
{
	int	i;
	int	width;
	int digs;

	i = 0;
	while (flagtypes(flags[i]) == 1)
		i++;
	width = 0;
	while (types(flags[i]) == 0)
	{
		width = width * 10 + (flags[i] - '0');
		i++;
	}
	return (width);
}
