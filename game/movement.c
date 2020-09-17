/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:26:40 by rlabrado          #+#    #+#             */
/*   Updated: 2020/09/17 14:02:22 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library.h"

int     pressed_key(int keycode, t_game *game)
{   
	if (keycode == KEY_W)
		game->raycast.move_up = 1;
	else if (keycode == KEY_S)
		game->raycast.move_down = 1;
	else if (keycode == KEY_D)
		game->raycast.move_right = 1;
	else if (keycode == KEY_A)
		game->raycast.move_left = 1;
	else if(keycode == KEY_ESC)
		exit(1);
        
    return (0);
}

int     released_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->raycast.move_up = 0;
	else if (keycode == KEY_S)
		game->raycast.move_down = 0;
	else if (keycode == KEY_D)
		game->raycast.move_right = 0;
	else if (keycode == KEY_A)
		game->raycast.move_left = 0;
        
    return (0);
}

int		run_game(t_game *game)
{
	if (game->raycast.move_up)
	{
		if (game->map->map_matrix[(int)(game->raycast.pos_x + game->raycast.dir_x * game->raycast.movement_speed)][(int)game->raycast.pos_y] != '1')
			game->raycast.pos_x += game->raycast.dir_x * game->raycast.movement_speed;
		if (game->map->map_matrix[(int)game->raycast.pos_x][(int)(game->raycast.pos_y + game->raycast.dir_y * game->raycast.movement_speed)] != '1')
			game->raycast.pos_y += game->raycast.dir_y * game->raycast.movement_speed;
	}

	if (game->raycast.move_down)
	{
		if (game->map->map_matrix[(int)(game->raycast.pos_x - game->raycast.dir_x * game->raycast.movement_speed)][(int)game->raycast.pos_y] != '1')
			game->raycast.pos_x -= game->raycast.dir_x * game->raycast.movement_speed;
		if (game->map->map_matrix[(int)game->raycast.pos_x][(int)(game->raycast.pos_y - game->raycast.dir_y * game->raycast.movement_speed)] != '1')
			game->raycast.pos_y -= game->raycast.dir_y * game->raycast.movement_speed;
	}

	if (game->raycast.move_right)
	{
		game->raycast.old_dir = game->raycast.dir_x;
		game->raycast.dir_x = game->raycast.dir_x * cos(-game->raycast.rotation_speed) - game->raycast.dir_y * sin(-game->raycast.rotation_speed);
		game->raycast.dir_y = game->raycast.old_dir * sin(-game->raycast.rotation_speed) + game->raycast.dir_y * cos(-game->raycast.rotation_speed);
		game->raycast.old_plane = game->raycast.plane_x;
		game->raycast.plane_x = game->raycast.plane_x * cos(-game->raycast.rotation_speed) - game->raycast.plane_y * sin(-game->raycast.rotation_speed);
		game->raycast.plane_y = game->raycast.old_plane * sin(-game->raycast.rotation_speed) + game->raycast.plane_y * cos(-game->raycast.rotation_speed);
	}

	if (game->raycast.move_left)
	{
		game->raycast.old_dir = game->raycast.dir_x;
		game->raycast.dir_x = game->raycast.dir_x * cos(game->raycast.rotation_speed) - game->raycast.dir_y * sin(game->raycast.rotation_speed);
		game->raycast.dir_y = game->raycast.old_dir * sin(game->raycast.rotation_speed) + game->raycast.dir_y * cos(game->raycast.rotation_speed);
		game->raycast.old_plane = game->raycast.plane_x;
		game->raycast.plane_x = game->raycast.plane_x * cos(game->raycast.rotation_speed) - game->raycast.plane_y * sin(game->raycast.rotation_speed);
		game->raycast.plane_y = game->raycast.old_plane * sin(game->raycast.rotation_speed) + game->raycast.plane_y * cos(game->raycast.rotation_speed);
	}
	
	raycast(game);
	return (0);
}

void	set_player_begining_position(t_game *game)
{
	char **matrix;
	int i = 0;
	int j = 0;

	matrix = game->map->map_matrix;
	while (i < game->map->map_height) {
		j = 0;
		while (j < game->map->map_width) {
			if (ft_check_if_character(matrix[i][j], "NSWE")) {
				game->raycast.player_position.y_grid = i;
				game->raycast.player_position.x_grid = j;
				game->raycast.player_position.x = (j * SQUARE_SIZE) + (SQUARE_SIZE / 2);
				game->raycast.player_position.y = (i * SQUARE_SIZE) + (SQUARE_SIZE / 2);
				return;
			}
			j++;
		}
		i++;
	}
}