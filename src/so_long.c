/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:35:06 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/16 10:35:45 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "So Long");
    vars.img = mlx_new_image(vars.mlx, 200, 200);
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, (1L<<0), closeWindow, &vars);
    ft_printf("\n Couleur en int : %d", create_trgb(0, 255, 0, 0));
    mlx_string_put(vars.mlx, vars.win, 10, 10, COLOR_RED, "Hello world!");
    mlx_loop(vars.mlx);
    return (0);
}