/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:18:13 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/20 15:37:44 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Function prints out a character to the standard output. Returns written count.
int	ft_print_char(char ch)
{
	int	count;

	count = write(1, &ch, 1);
	return (count);
}
