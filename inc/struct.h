/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:40:47 by codespace         #+#    #+#             */
/*   Updated: 2024/10/19 19:10:06 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
    double x;
    double y;
} t_vector;

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;

}	t_mlx;

typedef struct s_rgb
{
    int r;
    int g;
    int b;
} t_rgb;

typedef struct s_texture
{
    char    *east_wall;
    char    *west_wall;
    char    *north_wall;
    char    *south_wall;
    t_rgb   east_wall_rgb;
    t_rgb   west_wall_rgb;
    t_rgb   north_wall_rgb;
    t_rgb   south_wall_rgb;
    t_rgb   floor;
    t_rgb   ceiling;
    int     east_wall_is_xpm;
    int     west_wall_is_xpm;
    int     north_wall_is_xpm;
    int     south_wall_is_xpm;
    int     floor_is_rgb;
    int     ceiling_is_rgb;
} t_texture;

typedef struct s_texture_img {
    void    *img_ptr;
    char    *data;
    int     width;
    int     height;
    int     bpp;        // Bits per pixel
    int     size_line;
    int     endian;
} t_texture_img;
	

typedef struct s_map
{
    char        **map;
    int         height;
    int         width;
    t_texture   *texture;
} t_map;

typedef struct s_player {
    t_vector *pos;
    t_vector *dir;
    t_vector *plan;
} t_player;


typedef struct s_game
{
	t_mlx	*mlx;
	t_map	*map;
	t_img	img;
	t_texture_img	*textures[4];
	t_player *player;
}	t_game;

typedef struct s_ray
{
    int mapX;
    int mapY;
    int stepX;
    int stepY;
    int side;
    double  camX;
    double  ray_dirX;
    double  ray_dirY;
    double  side_distX;
    double  side_distY;
    double  delta_distX;
    double  delta_distY;
    double  perp_wall_dist;
    bool    wall_hit;
}   t_ray;



#endif