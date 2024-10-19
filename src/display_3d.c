/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:12:48 by baptistevie       #+#    #+#             */
/*   Updated: 2024/10/07 10:46:28 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_game *data)
{
	(void)data;
}

void	draw_floor(t_game *data)
{
	(void)data;
}

void	draw_background(t_game *data) // 
{
	int i;
	int	j;

	(void)data;
	i = 0;
	while (i <= WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			img_pix_put(&data->img, i, j, BLACK_PIXEL);
			j++;
		}
		i++;
	}
}