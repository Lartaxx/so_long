/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daboyer <daboyer@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:35:18 by daboyer           #+#    #+#             */
/*   Updated: 2023/03/21 11:58:44 by daboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../printf/printf.h"
# include "../gnl/get_next_line.h"
 #include <fcntl.h>

typedef struct s_vars
{
    void	*mlx;
    void	*win;
	void	*img_ground;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	char	**map;
	int 	height;
	int 	width;
	int 	x;
	int 	next_x;
	int 	y;
	int 	next_y;
	int 	moves;
}				t_vars;

enum {
	FORWARD = 119,
	BACKWARD = 115,
	LEFT = 97,
	RIGHT = 100,
	ON_DESTROY = 65307,
};

int    	closeWindow(t_vars *vars);
int 	key_hook(int keycode, t_vars *vars);
int		create_trgb(int t, int r, int g, int b);
void	init_map(t_vars *vars);
int		ft_strlen2(char *str);
void 	size_of_map(t_vars *data);
void 	malloc_tab(t_vars *data);
int 	print_map(t_vars *data);
int		map_have_errors(t_vars *data);
int		buttonPressed(int keycode, t_vars *vars);
void	player_move(t_vars *vars, int direction);
void	move_forward(t_vars *vars);
void	get_player_position(t_vars *vars);
void	move_backward(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
int		check_wall(t_vars *vars);
#endif
