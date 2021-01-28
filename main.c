/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:49:32 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/28 18:33:50 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);

int	main(void)
{
	char	*s1;
	char	d1[100];
	char	d2[100];
	char 	*ret;
	int		 fd;
	int		fd_2;
	char	buffer[100];
	char	buffer_2[100];

	printf("#1 strlen:\n");
	printf("expected : %lu\n", strlen("hi there"));
	printf("mine     : %lu\n", ft_strlen("hi there"));
	printf("expected : %lu\n", strlen("clouds look like sheep"));
	printf("mine     : %lu\n", ft_strlen("clouds look like sheep"));
	printf("\n");
	
	printf("#2 strcpy:\n");
	printf("mine	 : %s | %s\n", ft_strcpy(d2, "you are the best"), d2);
	printf("expected : %s | %s\n", strcpy(d1, "you are the best"), d1);
	printf("mine     : %s | %s\n", ft_strcpy(d2, "clouds look like sheep"), d2);
	printf("expected : %s | %s\n", strcpy(d1, "clouds look like sheep"), d1);
	printf("mine     : %s | %s\n", ft_strcpy(d2, ""), d2);
	printf("expected : %s | %s\n", strcpy(d1, ""), d1);
	printf("\n");

	printf("#3 strcmp: \n");
	printf("mine     : %d\n", ft_strcmp("abc", "abc"));
	printf("expected : %d\n", strcmp("abc", "abc"));
	printf("mine     : %d\n", ft_strcmp("abcd", "abc"));
	printf("expected : %d\n", strcmp("abcd", "abc"));
	printf("mine     : %d\n", ft_strcmp("abc", "abcd"));
	printf("expected : %d\n", strcmp("abc", "abcd"));
	printf("mine     : %d\n", ft_strcmp("s", ""));
	printf("\n");

	printf("| %zd \n", ft_write(1, s1, 15));
	printf("| %zd \n", write(1, s1, 15));
	strcpy(s1, "but it's a secret");
	printf("| %zd \n", ft_write(1, s1, 159));
	printf("| %zd \n", write(1, s1, 159));
	printf("| %zd \n", ft_write(1, s1, 159));
	printf("| %zd \n", write(1, s1, 159));
	printf("\n");

	printf("#4 write: \n");
	strcpy(s1, "i love pancakes");
	printf("mine     : ");
	fflush(stdout);
	printf(" | %zd | %d\n", ft_write(1, s1, 15), errno);
	printf("expected : ");
	fflush(stdout);
	printf(" | %zd | %d\n", write(1, s1, 15), errno);

	strcpy(s1, "but it is a secret");
	printf("mine     : ");
	fflush(stdout);
	printf(" | %zd | %d\n", ft_write(1, s1, 9), errno);
	printf("expected : ");
	fflush(stdout);
	printf(" | %zd | %d\n", write(1, s1, 9), errno);
	printf("\n");

	strcpy(s1, "");
	printf("mine     : ");
	fflush(stdout);
	printf(" | %zd | %d\n", ft_write(1, s1, 1), errno);
	printf("expected : ");
	fflush(stdout);
	printf(" | %zd | %d\n", write(1, s1, 1), errno);

	printf("mine     : ");
	fflush(stdout);
	strcpy(s1, "it is kind of nice");
	fd_2 = open("write_my_output.txt", O_RDWR);
	printf(" | %zd | %d\n", ft_write(fd_2, s1, 10), errno);
	strcpy(s1, "it is kind of nice");
	fd = open("write_expected_output.txt", O_RDWR);
	printf("expected : ");
	fflush(stdout);
	printf(" | %zd | %d\n", write(fd, s1, 10), errno);
	printf("\n");

	printf("#4 read: \n");
	fd = open("read_input.txt", O_RDWR);
	printf("mine     : %zd | %s | %d \n", ft_read(fd, buffer_2, 36), buffer_2, errno);
	lseek(fd, 0, SEEK_SET);
	printf("expected : %zd | %s | %d \n", read(fd, buffer, 36), buffer, errno);

	return (0);
}
