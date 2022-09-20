#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "Flagging now: %1234c";
	char	*out;
	int		i, j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			j = 0;
			while (str[i + j] != 'c')
				j++;
		}
		i++;
	}
	out = malloc(j * sizeof(*out));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			j = 0;
			while (str[i + j + 1] != 'c')
			{
				out[j] = str[i + j + 1];
				j++;
			}
			out[j] = '\0';
		}
		i++;
	}
	printf("In: %s, Flag: %s\n", str, out);
	free(out);
	return (0);
}