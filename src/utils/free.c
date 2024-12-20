/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:15:34 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/17 18:31:29 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <stdlib.h>

void	destroy_image(t_env *env)
{
	if (env->image)
	{
		mlx_destroy_image(env->mlx, env->image->img_ptr);
		free(env->image);
		env->image = NULL;
	}
}

void	destroy_window(t_env *env)
{
	if (env->win)
	{
		mlx_destroy_window(env->mlx, env->win);
		free(env->win);
		env->win = NULL;
	}
}

void	destroy_mlx(t_env *env)
{
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		env->mlx = NULL;
	}
}

void	free_map(t_map *map)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->points[y]);
		y++;
	}
	free(map->points);
	free(map);
}

void	free_env(t_env *env)
{
	if (env)
	{
		if (env->image)
		{
			if (env->image->img_ptr)
				mlx_destroy_image(env->mlx, env->image->img_ptr);
			free(env->image);
			env->image = NULL;
		}
		if (env->win)
		{
			mlx_destroy_window(env->mlx, env->win);
			env->win = NULL;
		}
		if (env->mlx)
		{
			mlx_destroy_display(env->mlx);
			free(env->mlx);
			env->mlx = NULL;
		}
		if (env->map)
			free_map(env->map);
		free(env);
	}
}
