//* Test
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int				count;
	int				i, len;
	char			ch;
	char			*str;
	unsigned int	u;

	i = 10;
	ch = 'A';
	str = "Hello";
	u = 150;
	count = 0;
	//*
	count = ft_printf("-----------ft_printf-----------\n");
	ft_printf("Count: %d\n", count);
	count = ft_printf("Char: %c\n", ch);//, Pointer: %p, String: %s\n", ch, str, str);
	/*
	count = ft_printf("Char: %c, Pointer: %p, String: %s\n", ch, str, str);
	ft_printf("Line: %d\n", len);
	count = ft_printf("Sgn int: %i, Sgn dec: %d, Usgn dec: %u\n", i, i, u);
	ft_printf("Line: %d\n", len);
	count = ft_printf("Usgn hex l: %x, Usgn hex U: %X, Percent: %%\n", u, u);
	ft_printf("Line: %d\n", len);
	ft_printf("Bonus\n");
	count = ft_printf("--flag: %-5d, 0-flag: %05d, .-flag: %.5d\n", i, i, i);
	ft_printf("Line: %d\n", len);
	count = ft_printf("#-flag: %#5X, _-flag: % 5d, +-flag: %+d\n", u, i, i);
	ft_printf("Line: %d\n", len);count/*/ft_
	len = printf("--------------printf-----------\n");
	printf("Count: %d\n", len);
	len = printf("Char: %c, Pointer: %p, String: %s\n", ch, str, str);
	printf("Line: %d\n", len);
	len = printf("Sgn int: %i, Sgn dec: %d, Usgn dec: %u\n", i, i, u);
	printf("Line: %d\n", len);
	len = printf("Usgn hex l: %x, Usgn hex U: %X, Percent: %%\n", u, u);
	printf("Line: %d\n", len);
	printf("Bonus\n");
	len = printf("--flag: %-5d, 0-flag: %05d, .-flag: %.5d\n", i, i, i);
	printf("Line: %d\n", len);
	len = printf("#-flag: %#5X, _-flag: % 5d, +-flag: %+d\n", u, i, i);
	printf("Line: %d\n", len);
	return (0);
}
//*/