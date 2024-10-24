/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:13:25 by bvieilhe          #+#    #+#             */
/*   Updated: 2024/10/24 16:24:31 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 600

# define BLUE_PIXEL 0xFF
# define GREEN_PIXEL 0xFF00
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF
# define MLX_ERROR 1
#define M_PI 3.14159265358979323846
# define BLACK_PIXEL 0x0

# define MOVE_SPEED 0.3f
# define ROTATE_SPEED 8.0f // Vitesse de rotation en degrés
# define DEG_TO_RAD(angle_in_degrees) ((angle_in_degrees)*M_PI / 180.0f)

# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

#endif