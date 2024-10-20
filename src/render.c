/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:26:37 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/10/20 18:15:45 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int render_3d(t_game *data)
{
	//mlx_destroy_image(data->mlx->mlx_ptr,data->img.mlx_img);
	draw_background(data);
	cast_rays(data);  // test
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
							data->img.mlx_img, 0, 0);
	return (0);
}
