//* Test
#include <stdio.h>

int	main(void)
{
	int				i;
	char			ch;
	char			*str;
	unsigned int	u;

	i = 10;
	ch = 'A';
	str = "Hello";
	u = 10;
	/*
	ft_printf("-----------ft_printf-----------\n");
	ft_printf("Char: %c, Pointer: %p, String: %s\n", ch, str, str);
	ft_printf("Sgn int: %i, Sgn dec: %d, Usgn dec: %u\n", i, i, u);
	ft_printf("Usgn hex l: %x, Usgn hex U: %X, Percent: %%\n", u, u);
	//*/
	printf("--------------printf-----------\n");
	printf("Char: %c, Pointer: %p, String: %s\n", ch, str, str);
	printf("Sgn int: %i, Sgn dec: %d, Usgn dec: %u\n", i, i, u);
	printf("Usgn hex l: %x, Usgn hex U: %X, Percent: %%\n", u, u);
	printf("Bonus\n");
	printf("--flag: %-5d, 0-flag: %05d, .-flag: %.5d\n", i, i, i);
	printf("#-flag: %#5X, _-flag: % 5d, +-flag: %+d\n", u, i, i);
	return (0);
}
//*/