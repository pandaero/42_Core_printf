/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:00:50 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 08:08:25 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_bonus.h"

//Function identifies a character as a format flag type. Returns 1 or 0.
int	flag_checker(char ch)
{
	if (ch == '-' || ch == '0' || ch == '.' || ch == '%')
		return (1);
	if (ch == '#' || ch == ' ' || ch == '+')
		return (1);
	return (0);
}

//Function reads format flags after a determined starting location. Alloc's str.
char	*flag_reader(const char * string, int start)
{
	char	*flagout;
	int		i;
	int		j;

	i = start;
	j = 0;
	while (string[i + j] != '\0' && type_checker(string[i + j]) == 0)
		j++;
	if (j == 1)
	{
		flagout = malloc(1 * sizeof(*flagout));
		flagout[0] = '\0';
		return (flagout);
	}
	flagout = malloc(j * sizeof(*flagout));
	j = 0;
	while (type_checker(string[i + j + 1]) == 0)
	{
		flagout[j] = string[i + j + 1];
		j++;
	}
	flagout[j] = '\0';
	return (flagout);
}
