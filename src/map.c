/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:08:05 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/16 12:13:07 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void size_of_map(t_vars *data)
{
	int fd;

	fd = open("map2.ber", O_RDONLY);
	data->width = ft_strlen2(get_next_line(fd)) - 1;
	data->height = 1;
	while(get_next_line(fd))
		data->height++;
}

void malloc_tab(t_vars *data)
{
	int 	i;
	int 	j;
	int 	fd;
	char 	*str;

	fd = open("map2.ber", O_RDONLY);
	i = 0;
	data->map = malloc(data->height + 1);
	while(i < data->height)
	{
		data->map[i] = malloc(data->width);
		i++;
	}
	str = get_next_line(fd);
	while(j < data->height)
	{
		data->map[j] = str;
		str = get_next_line(fd);
		j++;
	}
	j = 0;
	ft_printf("\n");
	while (j < data->height)
	{
		ft_printf("%s", data->map[j]);
		j++;
	}
	ft_printf("\n");
}

int print_map(t_vars *data)
{
	int 	img_width;
	int 	img_height;
	int i;
	int j;

	i = 0;
	j = 0;
	data->img_ground = mlx_xpm_file_to_image(data->mlx, "imgs/ground.xpm", &img_width, &img_height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "imgs/wall.xpm", &img_width, &img_height);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "imgs/player.xpm", &img_width, &img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "imgs/exit.xpm", &img_width, &img_height);
	while(i < data->height)
	{
		while(j < data->width)
		{
			if(data->map[i][j] == '1')
				mlx_put_image_to_window ( data->mlx, data->win, data->img_wall, j * 64, i * 64);
			if(data->map[i][j] == '0')
				mlx_put_image_to_window ( data->mlx, data->win, data->img_ground, j * 64, i * 64);
			if(data->map[i][j] == 'P')
				mlx_put_image_to_window ( data->mlx, data->win, data->img_player, data->y * 64, data->x * 64);
			if(data->map[i][j] == 'E')
				mlx_put_image_to_window ( data->mlx, data->win, data->img_exit, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}