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

void	size_of_map(t_vars *data)
{
	int		fd;

	fd = open("maps/map2.ber", O_RDONLY);
	data->width = ft_strlen(get_next_line(fd)) - 1;
	data->height = 1;
	while (get_next_line(fd))
		data->height++;
}

void	malloc_tab(t_vars *data)
{
	int		i;
	int		j;
	int		fd;
	char	*str;

	fd = open("maps/map2.ber", O_RDONLY);
	i = 0;
	data->map = malloc(data->height + 1);
	while (i < data->height)
	{
		data->map[i] = malloc(data->width);
		i++;
	}
	str = get_next_line(fd);
	while (j < data->height)
	{
		data->map[j] = str;
		str = get_next_line(fd);
		j++;
	}
	j = 0;
	while (j < data->height)
		j++;
}

int	print_map(t_vars *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	init_map(data);
	init_map2(data, i, j);
	return (0);
}
