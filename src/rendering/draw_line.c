/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:27:04 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 17:43:22 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <stdint.h>
#include <stdlib.h>

/**
 * @function : 	Initialise the bresenham algorithm. 
 * @param : dx, dy are the deltas
 * @param : sx, sy for step directions
 * @param : x0, y0 for initial points
 * @param : x1, y1 for derivated points
 * @param : err for error handling based on deltas soustracted
 *
 * @Conditions : initializing steps values depending on 
 * 				 intial and derivated values of x & y
 */
void	init_bresenham(t_point p1, t_point p2, t_bresenham *b)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = (int)p1.x_proj;
	y0 = (int)p1.y_proj;
	x1 = (int)p2.x_proj;
	y1 = (int)p2.y_proj;
	b->dx = abs(x1 - x0);
	b->dy = abs(y1 - y0);
	if (x0 < x1)
		b->sx = 1;
	else
		b->sx = -1;
	if (y0 < y1)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = (b->dx - b->dy);
	b->x = x0;
	b->y = y0;
}

/** @function : Performs a step in Bresenham's algorithm
 * 			    by updating the current position(x,y) 
 * 			    and adjusts the error term based on the 
 * 			    algorithm's logic
 * 	@param : e2 serves as a temp variable that holds twice the current
 * 			 error value. Multiplied twice because we mostly want to 
 * 			 avoid dealting with floating point numbers.
 *
 * 	@Conditions : based on 
 */
void	step_bresenham(t_bresenham *b)
{
	int	e2;

	e2 = 2 * b->err;
	if (e2 > -b->dy)
	{
		b->err = b->err - b->dy;
		b->x = b->x + b->sx;
	}
	if (e2 < b->dx)
	{
		b->err = b->err + b->dx;
		b->y = b->y + b->sy;
	}
}

uint32_t	get_color(int z)
{
	if (z < -10)
		return (COLOR_BLUE);
	else if (z < 0)
		return (COLOR_CYAN);
	else if (z < 10)
		return (COLOR_GREEN);
	else if (z < 20)
		return (COLOR_YELLOW);
	else
		return (COLOR_RED);
}

void	my_pixel_put(t_env *env, int x, int y, uint32_t color)
{
	char	*pixel;
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * env->image->line_len) + (x * (env->image->bpp) / 8);
	if (offset < 0 || offset >= (HEIGHT * env->image->line_len))
		return ;
	pixel = env->image->data_addr + offset;
	pixel[0] = (color >> 16) & 0xFF;
	pixel[1] = (color >> 8) & 0xFF;
	pixel[2] = color & 0xFF;
	if (env->image->bpp == 32)
		pixel[3] = 0;
}

/**
 * @function: Implements Bresenham's algorithm to draw lines 
 * between two points.
 *
 */
void	draw_line(t_env *env, t_point p1, t_point p2)
{
	t_bresenham	b;

	init_bresenham(p1, p2, &b);
	while (1)
	{
		my_pixel_put(env, b.x, b.y, p1.color);
		if (b.x == (int)p2.x_proj && b.y == (int)p2.y_proj)
			break ;
		step_bresenham(&b);
	}
}
