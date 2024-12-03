/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 07:17:38 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/01 07:31:04 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/Libft/libft.h"
# include "../lib/Libft/ft_printf.h"
# include "../lib/Libft/get_next_line_bonus.h"
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
# include "../inc/renderer.h"
# include "../inc/utils.h"
# include "../inc/draw_line.h"
# include "../inc/parser.h"
# include "../inc/parser_utils.h"
# include "../inc/input_handler.h"
# include "../inc/draw_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <math.h>

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
