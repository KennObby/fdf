/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_and_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:57:34 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 16:18:23 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

t_range	get_z_range(t_map *map)
{
	t_range	range;
	int		y;
	int		x;

	if (map == NULL || map->points == NULL)
	{
		range.min_z = 0;
		range.max_z = 0;
		return (range);
	}
	y = 0;
	range.min_z = map->points[0][0].z;
	range.max_z = map->points[0][0].z;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->points[y][x].z < range.min_z)
				range.min_z = map->points[y][x].z;
			if (map->points[y][x].z > range.max_z)
				range.max_z = map->points[y][x].z;
			x++;
		}
		y++;
	}
	return (range);
}

double	compute_scale(t_range range, t_env *env)
{
	double	scale_x;
	double	scale_y;
	double	scale_z;
	double	scale;

	if (env->map->width == 0 || env->map->height == 0)
		return (1.0);
	scale_x = (double)WIDTH / (env->map->width);
	scale_y = (double)HEIGHT / (env->map->height);
	if (range.min_z < 0 || range.max_z > 0)
		scale_z = (double)HEIGHT / (fabs(range.min_z)
				+ fabs(range.max_z)) / 4.0;
	else
		scale_z = 1.0;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	if (scale < scale_z)
		return (scale);
	else
		return (scale_z);
}

void	center_map(t_env *env, t_map *map)
{
	double	map_center_x;
	double	map_center_y;
	double	proj_center_x;
	double	proj_center_y;

	map_center_x = (map->width - 1) / 2.0;
	map_center_y = (map->height - 1) / 2.0;
	proj_center_x = map->points[(int)map_center_y][(int)map_center_x].x_proj;
	proj_center_y = map->points[(int)map_center_y][(int)map_center_x].y_proj;
	env->transform.translate_x = (double)WIDTH / 2.0 - proj_center_x;
	env->transform.translate_y = (double)HEIGHT / 2.0 - proj_center_y;
}

void	draw_neighbors(t_env *env, t_point *point)
{
	t_point	bottom;
	t_point	right;

	if (point->x < env->map->width - 1)
	{
		right = env->map->points[point->y][point->x + 1];
		project_point(env, &right);
		draw_line(env, *point, right);
	}
	if (point->y < env->map->height - 1)
	{
		bottom = env->map->points[point->y + 1][point->x];
		project_point(env, &bottom);
		draw_line(env, *point, bottom);
	}
}

void	project_and_draw(t_env *env)
{
	int		y;
	int		x;
	t_point	*current;

	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			current = &env->map->points[y][x];
			project_point(env, current);
			draw_neighbors(env, current);
			x++;
		}
		y++;
	}
}
