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

# include "fdf.h"
# include "renderer.h"

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

void	draw_line(t_env, t_point p1, t_point p2);
void	init_bresenham(t_point p1, t_point p2, t_bresenham *b);
void	step_bresenham(t_bresenham *b);
void	plot_pixel(t_env *env, int x, int y, int color);

#endif
