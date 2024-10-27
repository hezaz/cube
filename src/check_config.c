/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:33:34 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/10/27 15:52:00 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_rgb(t_rgb *rgb)
{
	return (rgb->r >= 0 && rgb->r < 256
		&& rgb->g >= 0 && rgb->g < 256
		&& rgb->b >= 0 && rgb->g < 256);
}

bool	is_valid_xpm(char *path)
{
	char	*tmp;

	tmp = path + ft_strlen(path) - 4;
	return (ft_strnstr(tmp, ".xpm", 4));
}
