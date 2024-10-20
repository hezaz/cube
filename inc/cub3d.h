/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:58:56 by codespace         #+#    #+#             */
/*   Updated: 2024/10/20 15:24:10 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/************* lib ******************/
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

/*********** minilibx ***************/
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/************* inc ******************/
# include "define.h"
# include "struct.h"

void  load_texture(void *mlx_ptr, char *path, t_texture_img *texture);
t_player		*init_player(t_map *map);
int				handle_keypress(int keysym, t_game *data);
int				get_texture_color(t_texture_img *texture, int x, int y);
// void			ft_error(char *msg);
// void		rotate_player(t_player *player, int direction);
// void		move_player(t_player *player, t_map *map, float move_step);

/**                 FUNCTIONS                   **/

/******************** main.c ********/
void		print_map(t_map *map);
void    go_load_textures(t_game *game);

/********** get_map.c **************/
t_map		*get_map(char *path);
void		get_map_dim(t_map *map, char *path);

/********** get_map_utils.c ********/
bool		is_texture_line(char *line);
bool		is_map_line(char *line);
int			is_rgb_color(char *line);
t_rgb		parse_rgb(char *line);
char		*skip_spaces(char *line);
void		get_texture_line(t_map *map, char *line);

void		get_map_line(t_map *map, char *line, int *row);
void		check_map(t_game *game);
void		handle_wall_texture(char *line, char **texture_path,
				t_rgb *texture_rgb, int *is_xpm);
void		handle_texture_north(t_map *map, char *line);
void		handle_texture_south(t_map *map, char *line);
void		handle_texture_east(t_map *map, char *line);
void		handle_texture_west(t_map *map, char *line);
void		handle_floor_ceiling_texture(char *line, t_rgb *texture_rgb, int *is_rgb);
void		handle_texture_floor(t_map *map, char *line);
void		handle_texture_ceiling(t_map *map, char *line);
void	error_and_exit(char *message, t_game *game);

/************* error.c *************/
void		ft_error(char *msg);
void		*garbage_collector(void *ptr, bool clean, t_game *game);

/************* hooks.c *************/
int			handle_no_event(void *data);
void		handle_input(t_game *game, int keysym);
int			handle_keyrelease(int keysym, void *data);

/************* img.c *************/
void		img_pix_put(t_img *img, int x, int y, int color);

/********** display_2d.c *************/
void	draw_tile(int x, int y, int color, t_game *data);
void	draw_map(t_game *data);
void    draw_player(t_game *data);

/********** player.c *************/
void handle_input(t_game *game, int keysym);
int handle_keypress(int keysym, t_game *game);

/********** render.c *************/
int			render_3d(t_game *data);

/********** init.c *************/
t_texture_img   *init_text_img(void);
t_map		*init_map(void);
t_mlx		*init_mlx(void);
t_img		init_img(void);
t_game		*init_game(void);

/********** move.c *************/
void    move_player(t_game *data, int x);
void    rotate_player(t_game *data, double angle);

/********** raycasting.c *************/
void	cast_rays(t_game *data);
void	get_position(t_game *data, t_ray *ray);
void	get_initial_values(t_game *data, t_ray *ray);
void	perform_dda(t_game *data, t_ray *ray);
int get_texture_color(t_texture_img *texture, int x, int y);
void	draw_line(t_game *data, t_ray *ray, int x);

/********** display_3d.c *************/
int	rgb_to_int(t_rgb rgb);
void	draw_ceiling(t_game *data);
void	draw_floor(t_game *data);
void	draw_background(t_game *data);



/********** rc_math.c *************/
// double		get_slope(double dir);
// double		get_next_horiz_wall(t_game *data, double ray_dir);
// double		get_next_verti_wall(t_game *data, double ray_dir);
// double		get_wall_dist(t_game *data, int ray_dir);

#endif