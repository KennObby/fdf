/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:20:40 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 16:25:53 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_H
# define DRAW_LINE_H

# include "types.h"
# include "fdf.h"

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	x;
	int	y;
}				t_bresenham;

uint32_t	get_color(int z);
void		draw_line(t_env *env, t_point p1, t_point p2);
void		init_bresenham(t_point p1, t_point p2, t_bresenham *b);
void		step_bresenham(t_bresenham *b);
void		my_pixel_put(t_env *env, int x, int y, uint32_t color);

# define COLOR_BLUE 0x0000FF
# define COLOR_CYAN 0x00FFFF
# define COLOR_GREEN 0x00FF00
# define COLOR_YELLOW 0xFFFF00
# define COLOR_RED 0xFF0000

#endif
