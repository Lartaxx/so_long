/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:41:01 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/04 21:00:05 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthexa(unsigned long long int *num, char *base)
{
	int							i;
	int							count;
	unsigned long long int		nbr;
	char						print[16];

	if (!num)
		return (ft_putstr("(nil)"));
	i = 0;
	count = 0;
	nbr = (size_t) num;
	count += ft_putstr("0x");
	while (nbr > 0)
	{
		print[i++] = base[nbr % 16];
		nbr /= 16;
	}
	while (i)
		count += ft_putchar(print[--i]);
	return (count);
}
