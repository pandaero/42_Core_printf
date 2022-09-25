/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:20:45 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/25 12:59:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Function prints an pointer address to standard output, unformatted.
int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count = ft_print_str(ptr);
		return (count);
	}
	count += hex_prefix_printer(1);
	count += ft_print_hex((unsigned long) ptr, 1);
	return (count);
}

/*Test
#include <stdio.h>

int	main(void)
{
	char	*ptr = "You\n";
	void	*vptr = 0;

	ft_print_ptr(vptr);
	ft_print_char('\n');
	printf("Null ptr: %p\n", vptr);
	ft_print_ptr(ptr);
	ft_print_char('\n');
	return (0);
}
//*/