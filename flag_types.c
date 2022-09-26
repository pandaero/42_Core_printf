/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:43:05 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 06:35:47 by pandalaf         ###   ########.fr       */
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

//Function determines whether hex prefix flag is called.
int	hexpre(const char *flags)
{
	int	i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

//Function determines whether plus sign flag is called.
int	plus(const char *flags)
{
	int	i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == '+')
			return (1);
		i++;
	}
	return (0);
}
