/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:08:15 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 12:16:35 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

//Function prints out a formatted hexadecimal number. Returns written count.
int	ft_print_hex_fmt(unsigned int num, const char *flags, int cas)
{
	if ((int) num + cas > 0)
		return (0);
	if (!flags)
		return (0);
	
	/*(1 is lowercase, 0 is uppercase)
	unsigned int	digs;
	unsigned int	count;

	digs = 0;
	if (n == 0)
		count = ft_print_char('0');
	while (n > 0)
	{
		n /= 16;
		digs++;
	}
	if (digs >= 16)
	{
		ft_print_hex_
	}
*/
	return (0);
}
