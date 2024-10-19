/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistevieilhescaze <baptistevieilhesc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:53:30 by baptistevie       #+#    #+#             */
/*   Updated: 2024/09/27 11:06:47 by baptistevie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED 
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED 
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED 
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED 
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED 

double  get_slope(double dir)
{
    return (tan(dir * M_PI / 180.0f)); // ratio :  2*pi / 360deg
}

double  get_next_horiz_wall(t_game *data, double ray_dir)
{
    double  y_intercept; // ordonee a l'origine (b)
    double  slope; // pente (a)
    
    int     i;
    double  pseudo_x; // x qu'on fait varier
    double  pseudo_y; // y qu'on calcule
    bool    wall_found;

    slope = get_slope(ray_dir);
    y_intercept = data->player->y - (slope * data->player->x); // y = ax + b  <=> b = y - ax
    // gestion de + ou - en fonction de la direction a faire?
    i = 1;
    wall_found = false;
    while (!wall_found)
    {
        modf(data->player->x, &pseudo_x); // prend la partie entiere de la position X
        pseudo_x += (double)i; // on lui ajoute le i entier pour check a chaque colone
        pseudo_y = slope * pseudo_x + y_intercept; // simplement y = ax + b
        if (pseudo_x < 0 || pseudo_x > data->map->width || pseudo_y < 0 || pseudo_y > data->map->width)
            return (nan("")); // ERROR CALCUL HORS MAP
        if (data->map->map[lround(floor(pseudo_y))][lround(pseudo_x)] == '1')
            wall_found = true;
        i++;
    }

    return (sqrt( (data->player->x - pseudo_x) * (data->player->x - pseudo_x)       // racine de { (xa-xb) * (xa-xb)        flemme fonction carre
                + (data->player->y - pseudo_y) * (data->player->y - pseudo_y)));    //             + (ya-yb) * (ya-yb) }  => pythagore
}

double  get_next_verti_wall(t_game *data, double ray_dir)
{
    double  y_intercept; // ordonee a l'origine (b)
    double  slope; // pente (a)
    
    int     i;
    double  pseudo_x; // x qu'on calcule
    double  pseudo_y; // y qu'on fait varier
    bool    wall_found;

    slope = get_slope(ray_dir);
    y_intercept = data->player->y - (slope * data->player->x); // y = ax + b  <=> b = y - ax
    // gestion de + ou - en fonction de la direction a faire?
    i = 1;
    wall_found = false;
    while (!wall_found)
    {

        modf(data->player->y, &pseudo_y); // prend la partie entiere de la position Y
        pseudo_y += (double)i; // on lui ajoute le i entier pour check a chaque ligne
        pseudo_x = (pseudo_y - y_intercept) / slope; // simplement x = (y-b)/a;
        if (pseudo_x < 0 || pseudo_x > data->map->width || pseudo_y < 0 || pseudo_y > data->map->width)
            return (nan("")); // ERROR CALCUL HORS MAP

        if (data->map->map[lround(floor(pseudo_y))][lround(pseudo_x)] == '1')
            wall_found = true;
        i++;
    }

    return (sqrt( (data->player->x - pseudo_x) * (data->player->x - pseudo_x)       // racine de { (xa-xb) * (xa-xb)        flemme fonction carre
                + (data->player->y - pseudo_y) * (data->player->y - pseudo_y)));    //             + (ya-yb) * (ya-yb) }  => pythagore
}

double  get_wall_dist(t_game *data, int ray_dir)
{
    if (get_next_horiz_wall(data, ray_dir) == nan(""))
        return (get_next_verti_wall(data, ray_dir));
    else if (get_next_verti_wall(data, ray_dir) == nan(""))
        return (get_next_horiz_wall(data, ray_dir));
    return (fmin(get_next_horiz_wall(data, ray_dir), get_next_verti_wall(data, ray_dir)));
}