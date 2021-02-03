/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:49:32 by mlebrun           #+#    #+#             */
/*   Updated: 2021/02/03 21:41:23 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);
int			ft_atoi_base(char *str, char *base);
int			atoi_base(char *str, char *base);
int			ft_list_size(t_list *begin_list);
int			list_size(t_list *begin_list);

int			list_size(t_list *begin_list)
{
	int		size;

	if (begin_list == NULL)
		return (0);
	size = 0;
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}	

int	main(void)
{
	char		*s1;
 	char		d1[100];
	char		d2[100];
	char 		*ret;
	int			 fd;
	int			fd_2;
	char		buffer[100];
	char		buffer_2[100];
	t_list		s;
	t_list		s2;
	t_list		s3;
	t_list		s4;
	t_list		*elem;

	printf("<--Mandatory part-->");
	printf("\n");
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
	printf("expected : %d\n", strcmp("s", ""));
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
	printf("\n");

	printf("#5 strdup: \n");
	printf("mine     : %s\n", s1 = ft_strdup("i wish i was a rainbow"));
	free(s1);
	printf("expected : %s\n", s1 = strdup("i wish i was a rainbow"));
	free(s1);
	printf("mine     : %s\n", s1 = ft_strdup(""));
	free(s1);
	printf("expected : %s\n", s1 = strdup(""));
	free(s1);
	printf("\n");

	printf("<--Bonus part-->\n");
	printf("\n");
	/*
	printf("#6 atoi_base: \n");
	printf("mine     : %d\n", ft_atoi_base("ff", "0123456789abcdef"));
	printf("expected : %d", atoi_base("ff", "0123456789abcdef"));
	printf("return = %d\n", ft_strcmp("s", "saaa"));
	printf("\n");
	*/

	printf("#8 list_size\n");	

	s.data = "hi ";
	s.next = &s2;
	s2.data = "my ";
	s2.next = &s3;
	s3.data = "friends\n";
	s3.next = 0;
	elem = &s;

	printf("mine     : %d\n", ft_list_size(elem));
	printf("expected : %d\n", list_size(elem));
	printf("\n");

	printf("mine     : %d\n", ft_list_size(NULL));
	printf("expected : %d\n", list_size(NULL));

	printf("\n");
	return (0);
}
