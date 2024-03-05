/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:20:03 by bsoykan           #+#    #+#             */
/*   Updated: 2023/12/12 14:00:27 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

enum e_keys
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
};

typedef struct s_list
{
	int		map_x;
	int		map_y;
	int		exit_count;
	int		player_count;
	int		coin_count;
	int		player_x;
	int		player_y;
	int		exit_x_location;
	int		exit_y_location;
	int		player_steps;
	char	**map;
	char	**control_copy_for_map;
	void	*mlx_ptr;
	void	*win;
	void	*player_image;
	void	*coin_image;
	void	*exit_image;
	void	*floor_image;
	void	*wall_image;
}				t_map;

void			is_not_expected_arg_name(char *arg, char *expected);
void			control_map_on_copied_map(t_map *all_data, int fd,
					char *map_name_for_fd);
int				map_size(int fd);
void			fd_check_is_null_true(t_map *all_data, int fd);
void			map_malloc_control(t_map *all_map);
void			free_map_all_of_them(t_map *all_map);
void			coin_counter(t_map *all_maps, int y, int x);
void			map_error_and_free(t_map *all_map, int map_y_value);
void			map_width_control_is_samelen(t_map *all_map, int fd);
void			p_e_c_01_control(t_map *all_maps);
void			wall_control_on_frame(t_map *all_maps, int y, int x);
void			pec01_counter(t_map *all_maps, int y, int x);
void			player_counter(t_map *all_maps, int y, int x);
void			exit_counter(t_map *all_maps, int y, int x);
void			control_every_achievement(t_map *all_maps, int y, int x);
void			every_coin_to_reach_control(char **map, int y, int x);
void			is_there_any_coin_unreachable(t_map *all_maps);
void			game_controls_and_start(t_map *all_data);
void			xpm_to_image(t_map *all_data);
void			image_to_window_locationby_location(t_map *all_data_location);
void			every_data_to_location(t_map *all_data_location, int y, int x);
void			close_image_for_esc_key(t_map *all_maps);
void			player_moves(t_map *all_data, int x, int y);
void			for_esc(t_map *all_maps, int error_code, int free_code);
int				control_keys_for_player(int key_value, t_map *all_data);
int				when_window_down(t_map *all_data_to_free);
void			if_file_empty(t_map *all_data, int all_y_len);
void			if_empty_file_to_abort(t_map *all_data, int all_y_len);
void			if_there_just_new_line(int x);
void			anything_other_than_pec01(t_map *all_maps, int y, int x);
char			**free_all(char **result);

#endif