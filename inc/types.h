/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:57:51 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/04 10:16:49 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "fdf.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	float	x_proj;
	float	y_proj;
}				t_point;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
}				t_map;

typedef struct s_transform
{
	float	scale;
	float	rotation_x;
	float	rotation_y;
	float	rotation_z;
	float	translate_x;
	float	translate_y;
}				t_transform;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_transform	transform;
}				t_env;

#endif
