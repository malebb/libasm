/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:49:32 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/28 10:55:21 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
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
	
	printf("#2 strcpy:\n");
	printf("expected : %s | %s\n", strcpy(d1, "you are the best"), d1);
	printf("mine	 : %s | %s\n", ft_strcpy(d2, "you are the best"), d2);
	printf("expected : %s | %s\n", strcpy(d1, "clouds look like sheep"), d1);
	printf("mine     : %s | %s\n", ft_strcpy(d2, "clouds look like sheep"), d2);
	printf("expected : %s | %s\n", strcpy(d1, ""), d1);
	printf("mine     : %s | %s\n", ft_strcpy(d2, ""), d2);
	printf("\n");
*/
	printf("#3 strcmp: \n");
	printf("expected : %d\n", strcmp("abc", "abc"));
	printf("mine     : %d\n", ft_strcmp("abc", "abc"));
	printf("expected : %d\n", strcmp("abcd", "abc"));
	printf("mine     : %d\n", ft_strcmp("abcd", "abc"));
	printf("expected : %d\n", strcmp("abc", "abcd"));
	printf("mine     : %d\n", ft_strcmp("abc", "abcd"));
	printf("expected : %d\n", strcmp("s", ""));
	printf("mine     : %d\n", ft_strcmp("s", ""));
	printf("\n");
	
	return (0);
}
