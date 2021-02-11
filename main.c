/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:49:32 by mlebrun           #+#    #+#             */
/*   Updated: 2021/02/11 18:13:07 by mlebrun          ###   ########.fr       */
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
void		list_push_front(t_list **begin_list, void *data);
void		ft_list_push_front(t_list **begin_list, void *data);
void		fill_address(char *dst, char *src);
void 		ft_list_sort(t_list **begin_list, int (*cmp)());
int			test_function(int (*ret_minus_one)());
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

void		free_fct(void *data)
{
	free(data);
}

void		list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list		*previous_elem;
	t_list		*next_elem;
	t_list		*first_elem;

	if (!begin_list || !(*begin_list) || !data_ref || !cmp || !free_fct)
		return ;
	first_elem = *begin_list;
	previous_elem = NULL;
	while (*begin_list != 0)
	{
		if ((*cmp)((*begin_list)->data, data_ref) == 0)
		{
			if (previous_elem != NULL)
				previous_elem->next = (*begin_list)->next;
			else
				first_elem = (*begin_list)->next;
			next_elem = (*begin_list)->next;
			(*free_fct)((*begin_list)->data);
			(*free_fct)(*begin_list);
			*begin_list = (*begin_list)->next;
		}
		else
		{
			previous_elem = *begin_list;
			*begin_list = (*begin_list)->next;
		}
	}
	*begin_list = first_elem;
}


t_list		*create_elem(void *data)
{
	t_list		*elem;

	if (!(elem = malloc(sizeof(t_list) * (1))))
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void		list_push_front(t_list **begin_list, void *data)
{
	t_list		*new_elem;

	if (!begin_list || !data)
		return ;
	new_elem = create_elem(data);
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

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

void	put_lst(t_list *begin_list)
{
	int		i;

	i = 1;
	while (begin_list != 0)
	{
		printf("link #%d : data = %s\n", i, (char *)begin_list->data);
		begin_list = begin_list->next;
		i++;
	}
}

void		list_sort(t_list **begin_list, int (*cmp)())
{
	t_list		*first_elem;
	void		*data;
	int			change;

	first_elem = *begin_list;
	while ((*begin_list)->next != 0)
	{
		change = 0;
		if ((*cmp)((*begin_list)->data, (*begin_list)->next->data) > 0)
		{
			data = (*begin_list)->data;
			(*begin_list)->data = (*begin_list)->next->data;
			(*begin_list)->next->data = data;
			*begin_list = first_elem;
			change = 1;
		}
		if (!change)
			*begin_list = (*begin_list)->next;
	}
	*begin_list = first_elem;
}

int		ft_print_arg(char *s1, char *s2)
{
//	printf("s1 = %s\n", s1);
//	printf("s2 = %s\n", s2);
	return ((signed)-1);
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
	t_list		*l;
	t_list		*elem;
	
	char		*str;

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

	printf("#2 list_push_front: \n");

	printf("\n");

	printf("initial list:\n");
	s.data = "my ";
	s.next = &s2;
	s2.data = "friends ";
	s2.next = 0;
	elem = &s;
	put_lst(elem);
	printf("\n");
	printf("mine	 :\n");
	ft_list_push_front(&elem, "hi ");
	put_lst(elem);

	printf("\n");

	printf("expected : \n");
	s.data = "my ";
	s.next = &s2;
	s2.data = "friends ";
	s2.next = 0;
	elem = &s;
	list_push_front(&elem, "hi ");
	put_lst(elem);
	printf("\n");
	
	elem = NULL;
	printf("initial  :\n");
	printf("<<empty list>>\n");
	printf("\n");
	printf("mine     : \n");
	ft_list_push_front(&elem, "first elem added");
	put_lst(elem);
	printf("\n");
	printf("expected : \n");
	elem = NULL;
	list_push_front(&elem, "first elem added");
	put_lst(elem);
	printf("\n");

	printf("#3 list_size:\n");

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

	printf("#4 list_sort:\n");
	elem = NULL;
	list_push_front(&elem, strdup("a"));
	list_push_front(&elem, strdup("b"));
	list_push_front(&elem, strdup("c"));
	list_push_front(&elem, strdup("d"));
	printf("\n");
	printf("\n");

	printf("initial :\n");
	put_lst(elem);
	printf("\n");
	printf("mine    : \n");
	ft_list_sort(&elem, strcmp);
	put_lst(elem);
	printf("\n");
	elem = NULL;
	list_push_front(&elem, strdup("a"));
	list_push_front(&elem, strdup("b"));
	list_push_front(&elem, strdup("c"));
	list_push_front(&elem, strdup("d"));

	printf("expected: \n");
	list_sort(&elem, strcmp);
	put_lst(elem);
	elem = NULL;
	list_push_front(&elem, strdup("hello France"));
	list_push_front(&elem, strdup("we are good"));
	list_push_front(&elem, strdup("i love water"));
	list_push_front(&elem, strdup("waves in the sea"));

	printf("initial :\n");
	put_lst(elem);
	printf("\n");
	printf("mine    : \n");
	ft_list_sort(&elem, strcmp);
	put_lst(elem);
	printf("\n");
	elem = NULL;
	list_push_front(&elem, strdup("hello France"));
	list_push_front(&elem, strdup("we are good"));
	list_push_front(&elem, strdup("i love water"));
	list_push_front(&elem, strdup("waves in the sea"));
	printf("expected  : \n");
	list_sort(&elem, strcmp);
	put_lst(elem);
	printf("\n");

	printf("#5 list_remove_if\n");
	elem = NULL;
	list_push_front(&elem, strdup("house"));
	list_push_front(&elem, strdup("my"));
	list_push_front(&elem, strdup("to"));
	list_push_front(&elem, strdup("to"));
	list_push_front(&elem, strdup("welcome"));

	printf("initial  :\n");
	put_lst(elem);
	printf("\n");
	printf("expected :\n");
	list_remove_if(&elem, "to", strcmp, free_fct);
	put_lst(elem);

	elem = NULL;
	list_push_front(&elem, strdup("house"));
	list_push_front(&elem, strdup("my"));
	list_push_front(&elem, strdup("to"));
	list_push_front(&elem, strdup("to"));
	list_push_front(&elem, strdup("welcome"));
	printf("mine     :\n");
	ft_list_remove_if(&elem, "to", strcmp, free_fct);
	put_lst(elem);
	printf("\n");
	
	printf("#1 atoi_base: \n");
	printf("mine     : %d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("expected : %d\n", atoi_base("2147483647", "0123456789"));
	printf("mine     : %d\n", ft_atoi_base("ff", "0123456789abcdef"));
	printf("expected : %d\n", atoi_base("ff", "0123456789abcdef"));
	printf("mine     : %d\n", ft_atoi_base("    +++---seeeeb156", "mybase"));
	printf("expected : %d\n", atoi_base("    +++---seeeeb156", "mybase"));
	printf("\n");
//	printf("ws = %d | %d | %d | %d | %d | %d\n", ' ', '\f', '\n', '\r', '\t', '\v');
	

	return (0);
}
