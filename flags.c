/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:27:10 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/20 15:21:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//Function identifies the format types. Returns 1 or 0.
int	types(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p' || ch == 's' || ch == 'x')
		return (1);
	else if (ch == 'd' || ch == 'i' || ch == 'u' || ch == 'X')
		return (1);
	return (0);
}

//Function reads a format variable type after a determined starting location.
char	typeread(const char *string, int start)
{
	int		i;

	i = 0;
	while (types(string[start + i]) == 0)
		i++;
	return (string[start + i]);
}

//Function reads format flags after a determined starting location. Alloc's str.
char	*flagread(const char * string, int start)
{
	char	*flagout;
	int		i;
	int		j;

	i = start;
	j = 0;
	while (string[i + j] != '\0' && types(string[i + j]) == 0)
		j++;
	if (j == 1)
	{
		flagout = malloc(1 * (*flagout));
		flagout[0] = '\0';
		return (flagout);
	}
	flagout = malloc(j * sizeof(*flagout));
	j = 0;
	while (types(string[i + j + 1]) == 0)
	{
		flagout[j] = string[i + j + 1];
		j++;
	}
	flagout[j] = '\0';
	return (flagout);
}