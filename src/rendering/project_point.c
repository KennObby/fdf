/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:52:01 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/17 22:32:06 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <math.h>

void	compute_sincos(t_transform *transform)
{
	transform->sincos.cx = cos(transform->rotation_x);
	transform->sincos.sx = sin(transform->rotation_x);
	transform->sincos.cy = cos(transform->rotation_y);
	transform->sincos.sy = sin(transform->rotation_y);
	transform->sincos.cz = cos(transform->rotation_z);
	transform->sincos.sz = sin(transform->rotation_z);
}

void	apply_rotation(t_point *point, t_transform *transform)
{
	double	x_rot;
	double	y_rot;
	double	z_rot;
	double	final_x;
	double	final_y;

	y_rot = point->y_iso * transform->sincos.cx
		- point->z_rot * transform->sincos.sx;
	z_rot = point->y_iso * transform->sincos.sx
		+ point->z_rot * transform->sincos.cx;
	x_rot = point->x_iso * transform->sincos.cy
		+ z_rot * transform->sincos.sy;
	z_rot = point->x_iso * transform->sincos.sy
		+ z_rot * transform->sincos.cy;
	final_x = x_rot * transform->sincos.cz
		- y_rot * transform->sincos.sz;
	final_y = x_rot * transform->sincos.sz
		+ y_rot * transform->sincos.cz;
	point->x_iso = final_x;
	point->y_iso = final_y;
	point->z_rot = z_rot;
}

void	apply_scaling_translation(t_point *point, t_transform *transform)
{
	point->x_iso *= transform->zoom;
	point->y_iso *= transform->zoom;
	point->x_proj = point->x_iso * transform->scale + transform->translate_x;
	point->y_proj = point->y_iso * transform->scale + transform->translate_y;
}

t_point	project_iso(t_env *env, t_point *point)
{
	t_point	projected;
	double	angle;

	angle = 0.523599;
	projected.x_iso = (point->x - point->y) * cos(angle);
	projected.y_iso = (point->x + point->y) * sin(angle)
		- (point->z * env->transform.z_scale);
	projected.z_rot = 0;
	return (projected);
}

void	project_point(t_env *env, t_point *point)
{
	t_point	projected;

	projected = project_iso(env, point);
	point->x_iso = projected.x_iso;
	point->y_iso = projected.y_iso;
	point->z_rot = projected.z_rot;
	apply_rotation(point, &env->transform);
	apply_scaling_translation(point, &env->transform);
}
