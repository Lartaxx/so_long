/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:35:35 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/04 19:23:29 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int		count;

	count = 1;
	if (n > 9)
	{
		count += ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
	{
		ft_putchar(n + 48);
	}
	return (count);
}
