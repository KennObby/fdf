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

#include "../../../inc/fdf.h"

void	project_point(t_env *env, t_point *point)
{
	float	angle;
	float	x_iso;
	float	y_iso;

	angle = 0.523599;
	x_iso = (point->x - point->y) * cos(angle);
	y_iso = (point->x + point->y) * sin(angle) - point->z;
	point->x_proj = x_iso * env->transform.scale + env->transform.translate_x;
	point->y_proj = y_iso * env->transform.scale + env->transform.translate_y;
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
