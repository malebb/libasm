/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:23:11 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/30 09:42:27 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
