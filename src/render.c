/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:26:37 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/10/07 10:46:52 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int render_2d(t_game *data)
{
	// draw_map(data);
	// draw_player(data);
	draw_background(data);
	cast_rays(data);  // test
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
							data->img.mlx_img, 0, 0);
	return (0);
}
