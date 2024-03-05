/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:43:46 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/12 13:40:01 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"

void	is_there_any_coin_unreachable(t_map *all_maps)
{
	int	x;
	int	y;
	int	for_zero;

	y = 0;
	for_zero = 1;
	while (y < all_maps->map_y)
	{
		x = 0;
		while (x < all_maps->map_x)
		{
			if (all_maps->control_copy_for_map[y][x] != '1'
					&& all_maps->control_copy_for_map[y][x] != '-'
					&& all_maps->control_copy_for_map[y][x] != '0')
				map_error_and_free(all_maps, (all_maps->map_y - for_zero));
			x++;
		}
		y++;
	}
}

void	xpm_to_image(t_map *all_data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	all_data->player_image
		= mlx_xpm_file_to_image(all_data->mlx_ptr, "textures/s.xpm", &x, &y);
	all_data->coin_image
		= mlx_xpm_file_to_image(all_data->mlx_ptr, "textures/g.xpm", &x, &y);
	all_data->exit_image
		= mlx_xpm_file_to_image(all_data->mlx_ptr, "textures/p.xpm", &x, &y);
	all_data->floor_image
		= mlx_xpm_file_to_image(all_data->mlx_ptr, "textures/f.xpm", &x, &y);
	all_data->wall_image
		= mlx_xpm_file_to_image(all_data->mlx_ptr, "textures/w.xpm", &x, &y);
	if (!all_data->player_image || !all_data->coin_image
		|| !all_data->exit_image || !all_data->floor_image
		|| !all_data->wall_image)
	{
		ft_putstr_fd("Error,Please check is there a any file\n", 2);
		map_error_and_free(all_data, 0);
		exit(1);
	}
}

void	image_to_window_locationby_location(t_map *all_data_location)
{
	int	x;
	int	y;

	y = 0;
	while (y < all_data_location->map_y)
	{
		x = 0;
		while (x < all_data_location->map_x)
		{
			every_data_to_location(all_data_location, y, x);
			x++;
		}
		y++;
	}
}

void	every_data_to_location(t_map *all_data_location, int y, int x)
{
	mlx_put_image_to_window(all_data_location->mlx_ptr,
		all_data_location->win,
		all_data_location->floor_image, x * 32, y * 32);
	if (all_data_location->map[y][x] == 'P')
		mlx_put_image_to_window(all_data_location->mlx_ptr,
			all_data_location->win, all_data_location->player_image,
			all_data_location->player_x * 32, all_data_location->player_y * 32);
	else if (all_data_location->map[y][x] == 'E')
		mlx_put_image_to_window(all_data_location->mlx_ptr,
			all_data_location->win,
			all_data_location->exit_image,
			all_data_location->exit_x_location * 32,
			all_data_location->exit_y_location * 32);
	else if (all_data_location->map[y][x] == 'C')
		mlx_put_image_to_window(all_data_location->mlx_ptr,
			all_data_location->win,
			all_data_location->coin_image, x * 32, y * 32);
	else if (all_data_location->map[y][x] == '1')
		mlx_put_image_to_window(all_data_location->mlx_ptr,
			all_data_location->win,
			all_data_location->wall_image, x * 32, y * 32);
}

void	game_controls_and_start(t_map *all_data)
{
	all_data->mlx_ptr = mlx_init();
	all_data->win
		= mlx_new_window(all_data->mlx_ptr,
			all_data->map_x * 32,
			all_data->map_y * 32, "so_long");
	xpm_to_image(all_data);
	image_to_window_locationby_location(all_data);
	mlx_hook(all_data->win, 2, 0, control_keys_for_player, all_data);
	mlx_hook(all_data->win, 17, 0, when_window_down, all_data);
	mlx_loop(all_data->mlx_ptr);
}
