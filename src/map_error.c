/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:58:58 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/21 11:59:00 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int 	map_surronded_of_1(t_vars *data)
{
    int 	i;
    int 	j;

    i = 0;
    j = 0;
    if(ft_strchr(data->map[data->height - 1], '1') == NULL)
        return (0);
    if(ft_strchr(data->map[0], '1') == NULL)
        return( 0);
    while(i < data->height)
    {
        if(ft_strchr("1", data->map[i][0]) == NULL)
            return (0);
        if(ft_strchr("1", data->map[i][data->width - 1]) == NULL)
            return (0);
        i++;
    }
    while(j < data->width)
    {
        if(ft_strchr("1", data->map[data->height - 1][j]) == NULL)
            return (0);
        if(ft_strchr("1", data->map[0][j]) == NULL)
            return (0);
        j++;
    }
    return (1);
}

static int 	search_01cep(t_vars *data)
{
    int 	i;
    int 	j;

    i = 0;
    j = 0;
    while(i < data->height)
    {
            while(j < data->width)
            {
                if(ft_strchr("01CEP\n", data->map[i][j]) == NULL)
                    return (0);
                j++;
            }
            j = 0;
            i++;
    }
    return (1);
}

int		map_have_errors(t_vars *data)
{
	if (map_surronded_of_1(data) == 0)
	{
		ft_printf("The map must be surronded of the one '1' character!");
		return (0);
	}
	if (search_01cep(data) == 0)
	{
		ft_printf("Only 01CEP characters is valid on the map!");
		return (0);
	}
	return (1);
}