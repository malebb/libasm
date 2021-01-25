#include <stdio.h>
#include <string.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src, size_t n);
int	main(void)
{
	char	*s1;
	char	d1[100];

	printf("#1 strlen:\n");
	printf("mine     : %lu\n", ft_strlen("hi there"));
	printf("expected : %lu\n", strlen("hi there"));
	printf("mine     : %lu\n", ft_strlen("clouds look like sheep"));
	printf("expected : %lu\n", strlen("clouds look like sheep"));
	printf("\n");
	printf("#2 strcpy:\n");
	strcpy(s1, "salut");
//	printf("mine     : %lu\n", ft_strcpy("s1"));
	printf("expected : %s\n", strcpy(d1, s1));
//	printf("mine     : %lu\n", ft_strcpy("clouds look like sheep"));
	strcpy(s1, "yes");
	printf("expected : %s\n", strcpy(d1, s1));

	return (0);
}
