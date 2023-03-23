/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:12:36 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/23 12:12:38 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_vars *data)
{
	int		img_width;
	int		img_height;

	data->img_ground = mlx_xpm_file_to_image(data->mlx, "imgs/ground.xpm",
			&img_width, &img_height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "imgs/wall.xpm",
			&img_width, &img_height);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "imgs/player.xpm",
			&img_width, &img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "imgs/exit.xpm",
			&img_width, &img_height);
	data->img_collect = mlx_xpm_file_to_image(data->mlx, "imgs/collect.xpm",
			&img_width, &img_height);
	data->img_rocket = mlx_xpm_file_to_image(data->mlx, "imgs/rocket.xpm",
			&img_width, &img_height);
}

void	init_map2(t_vars *data, int i, int j)
{
	while (i < data->height)
	{
		init_map3(data, i, j);
		j = 0;
		i++;
	}
}

void	init_map3(t_vars *data, int i, int j)
{
	while (j < data->width)
	{
		if (data->map[i][j] == '1')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img_wall, j * 64, i * 64);
		if (data->map[i][j] == '0')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img_ground, j * 64, i * 64);
		if (data->map[i][j] == 'P')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img_player, data->y * 64, data->x * 64);
		if (data->map[i][j] == 'E')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img_exit, j * 64, i * 64);
		if (data->map[i][j] == 'C')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img_collect, j * 64, i * 64);
		if (data->map[i][j] == 'R')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img_rocket, j * 64, i * 64);
		j++;
	}
}
