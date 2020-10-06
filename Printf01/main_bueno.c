#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%x%x%x%X%xˆ%x%x%X%x%X\n", 542353, -542354, 1232342, 254364, 65473, 2435235, -65474, -876543, 234241, 2346321);
	printf("%x%x%x%X%xˆ%x%x%X%x%X\n", 542353, -542354, 1232342, 254364, 65473, 2435235, -65474, -876543, 234241, 2346321);

	ft_printf("Hello world %25.15d %0.0d %0.0d\n", 42, 0, 1);
	printf("Hello world %25.15d %0.0d %0.0d\n", 42, 0, 1);
	system("leaks printf");
	return (0);
}
