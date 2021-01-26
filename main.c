#include <stdio.h>
#include <string.h>

//size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int	main(void)
{
	char	*s1;
	char	d1[100];
	char	d2[100];
	char 	*ret;
/*
	printf("#1 strlen:\n");
	printf("mine     : %lu\n", ft_strlen("hi there"));
	printf("expected : %lu\n", strlen("hi there"));
	printf("mine     : %lu\n", ft_strlen("clouds look like sheep"));
	printf("expected : %lu\n", strlen("clouds look like sheep"));
	printf("\n");
*/	
	printf("#2 strcpy:\n");
	printf("expected : %s | %s\n", strcpy(d1, "you are the best"), d1);
	printf("mine	 : %s | %s\n", ft_strcpy(d2, "you are the best"), d2);
	printf("expected : %s | %s\n", strcpy(d1, "clouds look like sheep"), d1);
	printf("mine     : %s | %s\n", ft_strcpy(d2, "clouds look like sheep"), d2);
	printf("expected : %s | %s\n", strcpy(d1, ""), d1);
	printf("mine     : %s | %s\n", ft_strcpy(d2, ""), d2);
//	strcpy(s1, "yes");
//	printf("expected : %s\n", strcpy(d1, "fire is hot so don't touch it"));
	return (0);
}
