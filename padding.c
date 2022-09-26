/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 06:33:55 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 07:05:18 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function identifies a character as a format flag type except for zero padding.
static int	flagtypesnonzero(char ch)
{
	if (ch == '-' || ch == '.' || ch == '%')
		return (1);
	if (ch == '#' || ch == ' ' || ch == '+')
		return (1);
	return (0);
}

//Function returns whether zero padding flag is called.
int	zeropad(const char *flags)
{
	int	i;

	i = 0;
	if (flags [i + 1] == '0')
		return (1);
	i++;
	while (flagtypesnonzero(flags[i]) == 1)
		i++;
	if (flags[i] == '0')
		return (1);
	return (0);
}

//Function determines whether blank padding flag is called.
int	blankpad(const char *flags)
{
	int	i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
