/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:22:09 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/04 18:30:24 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				len;

	len = 1;
	if (n < 0)
	{
		ft_putchar('-');
		len++;
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		len += ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
	return (len);
}
