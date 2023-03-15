/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:07:01 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/06 09:01:19 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);

int		ft_putstr(const char *str);

int		ft_putnbr(int n);

int		ft_putnbr_u(unsigned int n);

int		ft_putnbr_base(int nbr, char *base);

int		ft_puthexa(unsigned long long int *num, char *base);

int		ft_printf(const char *str, ...);
#endif
