/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:40:47 by codespace         #+#    #+#             */
/*   Updated: 2024/11/24 14:45:33 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_texture
{
	char			*east_wall;
	char			*west_wall;
	char			*north_wall;
	char			*south_wall;
	t_rgb			floor;
	t_rgb			ceiling;
	int				east_wall_is_xpm;
	int				west_wall_is_xpm;
	int				north_wall_is_xpm;
	int				south_wall_is_xpm;
	int				floor_is_rgb;
	int				ceiling_is_rgb;
}					t_texture;

typedef struct s_texture_img
{
	void			*img_ptr;
	t_rgb			*rgb;
	char			*data;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
}					t_texture_img;

typedef struct s_map
{
	char			**map;
	int				map_error;
	int				valid_map;
	int				map_hasNL;
	int				nbr_p;
	int				height;
	int				width;
	t_texture		*texture;
}					t_map;

typedef struct s_player
{
	t_vector		*pos;
	t_vector		*dir;
	t_vector		*plan;
}					t_player;

typedef struct s_game
{
	t_mlx			*mlx;
	t_map			*map;
	t_img			img;
	t_texture_img	*textures[4];
	t_player		*player;
}					t_game;

typedef struct s_ray
{
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	double			cam_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	bool			wall_hit;
}					t_ray;

typedef struct s_draw_params
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	t_texture_img	*texture;
}					t_draw_params;

#endif