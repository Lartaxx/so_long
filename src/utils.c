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

int    closeWindow(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int		buttonPressed(int keycode, t_vars *vars)
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

int		key_hook(int keycode, t_vars *vars)
{
	vars = (t_vars *)vars;
	printf("Touche pressée: %d\n", keycode);
	return (0);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int ft_strlen2(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}