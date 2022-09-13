#include <stdarg.h>
#include <stdio.h>

int	addnumbers(int n, ...)
{
	int	sum;
	int	i;

	//Declare a pointer to the argument list
	va_list ptr;

	//Initialisation through first value, number of elements
	va_start(ptr, n);

	sum = 0;
	i = 0;
	while (i < n)
	{
		sum += va_arg(ptr, int);
		i++;
	}
	return (sum);
}

int	writestrings(const char *string, ...)
{
	int		i;
	int		count;
	va_list	ptr;
	char	*temp;

	count = 1;
	va_start(ptr, string);
	printf(string);
	temp = "";
	while (!temp);	
	{
		temp = (va_arg(ptr, char *));
		printf(temp);
		count++;
	}
	printf(va_arg(ptr, char *));
	count++;
	return (count);
}

int	main(void)
{
	int	x;

	printf("Lame sum 1-3: %d\n", addnumbers(3, 1, 2, 3));
	printf("Strings: ");
	x = writestrings("Hello, ", "wuu2", " bruh?");
	printf("\n");
	printf("Out: %d\n", x);
	return (0);
}