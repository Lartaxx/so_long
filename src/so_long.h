/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:35:18 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/15 21:48:28 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "../printf/printf.h"

typedef struct s_vars
{
    void	*mlx;
    void	*win;
}				t_vars;

enum {
	ON_KEYDOWN = 65364,
	ON_KEYUP = 65362,
	ON_DESTROY = 65307,
};

int    	closeWindow(int keycode, t_vars *vars);
int 	key_hook(int keycode, t_vars *vars);
#endif