/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:04:29 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/20 18:10:43 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_print_int(int num)
{
	int	count;

	count = 0;
	if (num == INT_MIN)
	{
		count = write(1, "-2147483648", 12);
		return (count);
	}
	if (num < 0)
	{
		num = -num;
		count += ft_print_char('-');
	}
	if (num / 10)
		count += ft_print_int(num / 10);
	count += ft_print_char((num % 10) + '0');
	return (count);
}
