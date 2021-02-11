/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:04:52 by mlebrun           #+#    #+#             */
/*   Updated: 2021/02/11 20:04:54 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		ft_is_base_valid(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
		i++;
	if (i == 0 || i == 1)
		return (0);
	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t'
			|| base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			return (0);
		j = -1;
		while (base[++j] != '\0')
		{
			if ((base[j] == base[i]) && j != i)
				return (0);
		}
	}
	return (1);
}

int		ft_char_in_base(char c, char *base)
{
	int		i;

	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == c)
			return (i);
	}
	return (-1);
}

int		skip_spaces(char *str)
{
	int		i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int		ft_convert_nbr(char *str, char *base, int base_size)
{
	int		i;
	int		nb;
	int		pos_in_base;

	nb = 0;
	i = 0;
	nb = 0;
	while ((pos_in_base = ft_char_in_base(str[i], base)) != -1)
	{
		nb *= base_size;
		nb += pos_in_base;
		i++;
	}
	return (nb);
}

int		atoi_base(char *str, char *base)
{
	int			i;
	int			pos_or_neg;
	long int	nb;
	int			base_size;

	if (!ft_is_base_valid(base))
		return (0);
	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	i = skip_spaces(str);
	pos_or_neg = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos_or_neg *= -1;
		i++;
	}
	nb = ft_convert_nbr(&str[i], base, base_size);
	return (nb * pos_or_neg);
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

int		main(void)
{
	t_list		s;
	t_list		s2;
	t_list		s3;
	t_list		s4;
	t_list		*l;
	t_list		*elem;

	printf("<--Bonus part-->\n");

	printf("\n");
	printf("#1 atoi_base: \n");
	printf("mine     : %d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("expected : %d\n", atoi_base("2147483647", "0123456789"));
	printf("mine     : %d\n", ft_atoi_base("ff", "0123456789abcdef"));
	printf("expected : %d\n", atoi_base("ff", "0123456789abcdef"));
	printf("mine     : %d\n", ft_atoi_base("    +++---seeeeb156", "mybase"));
	printf("expected : %d\n", atoi_base("    +++---seeeeb156", "mybase"));
	printf("mine     : %d\n", ft_atoi_base("456", ""));
	printf("expected : %d\n", atoi_base("456", ""));
	printf("mine     : %d\n", ft_atoi_base("456", "4"));
	printf("expected : %d\n", atoi_base("456", "4"));
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
	printf("\n");

	printf("expected: \n");
	list_sort(&elem, strcmp);
	put_lst(elem);
	elem = NULL;
	list_push_front(&elem, strdup("hello France"));
	list_push_front(&elem, strdup("we are good"));
	list_push_front(&elem, strdup("i love water"));
	list_push_front(&elem, strdup("waves in the sea"));
	printf("\n");

	printf("initial :\n");
	put_lst(elem);
	printf("\n");
	printf("mine      : \n");
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
	
	return (0);
}
