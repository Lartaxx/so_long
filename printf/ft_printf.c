/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:01:01 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/06 09:08:59 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include <stdio.h>

static char	*ft_readtext(const char *str, int *ret)
{
	int	len;

	len = 0;
	while (*str && *str != '%')
	{
		ft_putchar(*str);
		len++;
		str++;
	}
	*ret += len;
	return ((char *)str);
}

static char	*ft_search_args(const char *str, va_list list, int *ret)
{
	char	*format;

	if (*str == 'c')
		*ret += ft_putchar((char)va_arg(list, int));
	else if (*str == 's')
		*ret += ft_putstr(va_arg(list, char *));
	else if (*str == 'd' || *str == 'i')
		*ret += ft_putnbr(va_arg(list, int));
	else if (*str == 'u')
		*ret += ft_putnbr_u((unsigned int)va_arg(list, unsigned int));
	else if (*str == 'x')
		*ret += ft_putnbr_base(va_arg(list, int), "0123456789abcdef");
	else if (*str == 'X')
		*ret += ft_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
	else if (*str == 'p')
	{
		format = "0123456789abcdef";
		*ret += ft_puthexa(va_arg(list, void *), format);
	}
	else if (*str == '%')
		*ret += ft_putchar('%');
	else
		return (NULL);
	str++;
	return ((char *)str);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		ret;

	va_start(list, str);
	ret = 0;
	while (*str)
	{
		if (*str == '%')
			str = ft_search_args(str + 1, list, &ret);
		else
			str = ft_readtext(str, &ret);
		if (!str)
		{
			va_end(list);
			return (-1);
		}
	}
	va_end(list);
	return (ret);
}
