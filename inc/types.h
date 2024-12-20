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
	int			x;
	int			y;
	int			z;
	uint32_t	color;
	double		x_iso;
	double		y_iso;
	double		z_rot;
	double		x_proj;
	double		y_proj;
}				t_point;

typedef struct s_sincos_axis
{
	double	cx;
	double	sx;
	double	cy;
	double	sy;
	double	cz;
	double	sz;
}				t_sincos_axis;

typedef struct s_image
{
	void	*img_ptr;
	void	*data_addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_range
{
	double		min_z;
	double		max_z;
}				t_range;

typedef struct s_mouse
{
	int		is_dragging;
	int		last_x;
	int		last_y;
}				t_mouse;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
}				t_map;

typedef struct s_transform
{
	double			scale;
	double			z_scale;
	double			zoom;
	double			rotation_x;
	double			rotation_y;
	double			rotation_z;
	double			translate_x;
	double			translate_y;
	t_sincos_axis	sincos;
}				t_transform;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	t_mouse		mouse;
	t_image		*image;
	t_map		*map;
	t_transform	transform;
}				t_env;

#endif
