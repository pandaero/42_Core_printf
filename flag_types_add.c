/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_types_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:46:19 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/20 18:53:36 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
