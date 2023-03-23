/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:10:42 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/16 09:06:42 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	button_pressed(int keycode, t_vars *vars)
{
	if (keycode == ON_DESTROY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == FORWARD)
		player_move(vars, 1);
	if (keycode == BACKWARD)
		player_move(vars, 2);
	if (keycode == LEFT)
		player_move(vars, 3);
	if (keycode == RIGHT)
		player_move(vars, 4);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars = (t_vars *)vars;
	printf("Touche pressée: %d\n", keycode);
	return (0);
}

static size_t	ft_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = n;
	len = ft_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		len--;
		str[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (str);
}
