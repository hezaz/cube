/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:58:56 by codespace         #+#    #+#             */
/*   Updated: 2024/11/22 12:05:04 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/************* lib ******************/
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

/*********** minilibx ***************/
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/************* inc ******************/
# include "define.h"
# include "struct.h"

/**                 FUNCTIONS                   **/

/******************** check_config.c ********/
bool			is_valid_rgb(t_rgb *rgb);
bool			is_valid_xpm(char *path);

/******************** check_map.c ********/
int				is_valid_character(char c);
int				calculate_max_width(char **map, int height);
void			check_top_border(char **map, int max_width, t_game *game);
void			check_bottom_border(char **map, int height, int max_width,
					t_game *game);
void			check_left_right_borders(char **map, int height, t_game *game);

/******************** check_map2.c ********/
void			check_inner_part(char **map, int height, t_game *game);
void			check_map(t_game *game);

/********** close_game.c *************/
void			close_game(t_game *game);

/********** display_2d.c *************/
void			draw_tile(int x, int y, int color, t_game *data);
void			draw_map(t_game *data);
void			draw_player(t_game *data);

/********** display_3d.c *************/
int				rgb_to_int(t_rgb rgb);
void			draw_ceiling(t_game *data);
void			draw_floor(t_game *data);
void			draw_background(t_game *data);

/************* error.c *************/
void			ft_error(char *msg);
void			error_and_exit(char *message, t_game *game);
void			delete_node(void *ptr);
// void			*garbage_collector(void *ptr, bool clean, t_game *game);

/************* free.c *************/
void			free_textures(t_game *game);
void			free_walls(t_game *game);
void			free_mlx(t_game *game);
void			free_map(t_game *game);
void			free_player(t_player *player);

/********** get_map_utils.c ********/
bool			is_texture_line(char *line);
bool			is_map_line(char *line);
bool			get_texture_line(t_map *map, char *line);
void			get_map_line(t_map *map, char *line, int *row);

/********** get_map.c **************/
void			initialize_map(t_map *map, char *path);
void			process_map_file(int fd, t_map *map);
void			process_line(char *line, int *cpt, t_map *map, int *row);
t_map			*get_map(char *path);
void			get_map_dim(t_map *map, char *path);

/************* hooks.c *************/
int				handle_no_event(void *data);
int				handle_keyrelease(int keysym, void *data);

/************* img.c *************/
void			img_pix_put(t_img *img, int x, int y, int color);

/********** init_player.c *************/
void			set_player_direction(char direction, t_player *player);
t_player		*find_player_position(t_map *map, t_player *player);
t_player		*init_player(t_map *map);

/********** init_textures.c *************/
void			load_texture(void *mlx_ptr, char *path, t_texture_img *texture);
void			go_load_textures(t_game *game);
t_texture_img	*init_text_img(void);
void			init_texture(t_texture *texture);
void			init_rgb(t_rgb *rgb);

/********** init.c *************/
t_vector		*init_vector(double x, double y);
t_map			*init_map(void);
t_mlx			*init_mlx(void);
t_img			init_img(void);
t_game			*init_game(void);

/********** move.c *************/
void			move_player(t_game *data, int x, int y);
void			rotate_player(t_game *data, double angle);
double			deg_to_rad(double angle_in_degrees);

/********** player.c *************/
void			handle_input(t_game *game, int keysym);
int				handle_keypress(int keysym, t_game *game);

/********** raycast_textures.c ********/
void			calculate_line_dimensions(t_ray *ray, int *line_height,
					int *draw_start, int *draw_end);
double			calculate_wallx(t_game *data, t_ray *ray);
int				adjust_texture_x(t_ray *ray, t_texture_img *texture,
					double wallX);
void			draw_texture_line(t_game *data, t_ray *ray, int x,
					t_draw_params *params);

/********** raycasting.c *************/
void			draw_line(t_game *data, t_ray *ray, int x);
void			perform_dda(t_game *data, t_ray *ray);
void			get_initial_values(t_game *data, t_ray *ray);
void			get_position(t_game *data, t_ray *ray);
void			cast_rays(t_game *data);

/********** render.c *************/
int				render_3d(t_game *data);

/********** texture_floor.c *************/
bool			handle_floor_ceiling_texture(char *line, t_rgb *rgb,
					int *is_rgb);
bool			handle_texture_floor(t_map *map, char *line);
bool			handle_texture_ceiling(t_map *map, char *line);

/********** texture_utils.c *************/
char			*skip_spaces(char *line);
int				is_rgb_color(char *line);
t_rgb			parse_rgb(char *line);
t_texture_img	*select_texture(t_game *data, t_ray *ray);
int				get_texture_color(t_texture_img *texture, int x, int y);

/********** texture_wall.c *************/
bool			handle_wall_texture(char *line, char **path,
					int *is_xpm);
bool			handle_texture_north(t_map *map, char *line);
bool			handle_texture_south(t_map *map, char *line);
bool			handle_texture_east(t_map *map, char *line);
bool			handle_texture_west(t_map *map, char *line);

#endif