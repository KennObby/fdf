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

#include "../../../inc/fdf.h"
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

/** @function : abstracts the mlx_pixel_put call for plotting 
 * 			   for individual pixels.
 */
void	plot_pixel(t_env *env, int x, int y, int color)
{
	mlx_pixel_put(env->mlx, env->win, x, y, color);
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
		plot_pixel(env, b.x, b.y, p1.color);
		if (b.x == (int)p2.x_proj && b.y == (int)p2.y_proj)
			break ;
		step_bresenham(&b);
	}
}
