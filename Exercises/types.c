#include <stdlib.h>
#include <stdio.h>

//Function identifies the format types. Returns 1 or 0.
int	types(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p' || ch == 's' || ch == 'x')
		return (1);
	else if (ch == 'd' || ch == 'i' || ch == 'u' || ch == 'X')
		return (1);
	return (0);
}

//Function reads format flags after a determined starting location.
char	typeread(char *string, int start)
{
	int		i;

	i = 0;
	while (types(string[start + i]) == 0)
		i++;
	return (string[start + i]);
}

int	main(void)
{
	char	str1[] = "Flag now: %1234c";
	char	str2[] = "flags %44i and %as and why not %c";
	char	out1, out2, out3, out4;

	out2 = typeread(str2, 6);
	out3 = typeread(str2, 15);
	out4 = typeread(str2, 31);
	printf("In: %s, Type: %c\n", str1, typeread(str1, 10));
	printf("In: %s, Type1: %c, Type2: %c, Type3: %c\n", str2, out2, out3, out4);
	return (0);
}