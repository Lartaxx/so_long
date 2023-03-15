/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:10:42 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/15 21:52:22 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    closeWindow(int keycode, t_vars *vars)
{
    keycode = (int)keycode;
    if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}

int key_hook(int keycode, t_vars *vars)
{
    vars = (t_vars *)vars;
    printf("Touche pressée: %d\n", keycode);
    return (0);
}