/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:23:10 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/06 09:08:35 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static void	rec(unsigned int n, const char *b, size_t bl, int *c)
{
	if (n >= bl)
	{
		rec(n / bl, b, bl, c);
		rec(n % bl, b, bl, c);
	}
	else
	{
		ft_putchar(b[n]);
		(*c)++;
	}
}

int	ft_putnbr_base(int nbr, char *base)
{
	int					base_len;
	unsigned int		nb;
	int					count;

	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (0);
	count = 0;
	nb = nbr;
	rec(nb, base, base_len, &count);
	return (count);
}
