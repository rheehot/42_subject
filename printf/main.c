#include <string.h>


int		ft_printf(const char *fmt, ...);

int		main(void)
{
	ft_printf("%12.4s\n", "hello, world!");
	ft_printf("%10.5d\n", 1010);
	ft_printf("%10c\n", '\0');
	ft_printf("%s\n", NULL);

	for(;;);
}
