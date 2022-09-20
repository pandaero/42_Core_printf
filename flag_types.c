/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:43:05 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/20 18:54:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function returns whether left align flag is called.
int	leftalign(const char *flags)
{
	int	i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

//Function returns whether zero padding flag is called.
int	zeropad(const char *flags)
{
	int	i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

//Function returns whether precision flag is called.
int	precision(const char *flags)
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
