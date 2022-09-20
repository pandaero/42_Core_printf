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
char	*flagread(char * string, int start)
{
	char	*flagout;
	int		i;
	int		j;

	i = start;
	j = 0;
	while (string[i + j] != '\0' && types(string[i + j]) == 0)
		j++;
	if (j == 1)
	{
		flagout = malloc(1 * (*flagout));
		flagout[0] = '\0';
		return (flagout);
	}
	flagout = malloc(j * sizeof(*flagout));
	j = 0;
	while (types(string[i + j + 1]) == 0)
	{
		flagout[j] = string[i + j + 1];
		j++;
	}
	flagout[j] = '\0';
	return (flagout);
}

int	main(void)
{
	char	str1[] = "Flag now: %1234c";
	char	str2[] = "flags %44i and %as and why not %c";
	char	*out1, *out2, *out3, *out4;

	out1 = flagread(str1, 10);
	out2 = flagread(str2, 6);
	out3 = flagread(str2, 15);
	out4 = flagread(str2, 31);
	printf("In: %s, Flag: %s\n", str1, out1);
	printf("In: %s, Flag1: %s, Flag2: %s, Flag3: %s\n", str2, out2, out3, out4);
	return (0);
}