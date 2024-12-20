/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:17:00 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 15:56:07 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <stddef.h>
#include <stdint.h>

void	clear_image(t_env *env, uint32_t color)
{
	int		x;
	int		y;
	char	*pixel;

	if (!env->image || !env->image->data_addr)
		return ;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		pixel = env->image->data_addr + y * env->image->line_len;
		while (x < WIDTH)
		{
			pixel[0] = (color >> 16) & 0xFF;
			pixel[1] = (color >> 8) & 0xFF;
			pixel[2] = color & 0xFF;
			if (env->image->bpp == 32)
				pixel[3] = 0;
			pixel += env->image->bpp / 8;
			x++;
		}
		y++;
	}
}

t_image	*init_image(t_env *env)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (image == NULL)
		error_exit("Failed to allocate memory for an image", env);
	image->img_ptr = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (image->img_ptr == NULL)
	{
		free(image);
		error_exit("Failed to create new image", env);
	}
	image->data_addr = mlx_get_data_addr(image->img_ptr, &image->bpp,
			&image->line_len, &image->endian);
	if (image->data_addr == NULL)
	{
		mlx_destroy_image(env->mlx, image->img_ptr);
		free(image);
		error_exit("Failed to get image data address", env);
	}
	return (image);
}

int	init_window(t_env *env)
{
	int		map_center_x;
	int		map_center_y;
	double	scale_x;
	double	scale_y;
	double	min_scale;

	env->mlx = mlx_init();
	if (!env->mlx)
		return (-1);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FdF oilyine-");
	if (!env->win)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		error_exit("Failed to initialize the window.", env);
		return (-1);
	}
	scale_x = (double)WIDTH / (env->map->width * 5);
	scale_y = (double)HEIGHT / (env->map->height * 5);
	if (scale_x < scale_y)
		min_scale = scale_x;
	else
		min_scale = scale_y;
	env->transform.scale = min_scale;
	map_center_x = (env->map->width * env->transform.scale) / 2;
	map_center_y = (env->map->height * env->transform.scale) / 2;
	env->transform.translate_x = (WIDTH / 2) - map_center_x;
	env->transform.translate_y = (HEIGHT / 2) - map_center_y;
	return (0);
}

t_env	*init_env(t_map *map)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (NULL);
	env->map = map;
	env->transform.scale = 20.0;
	env->transform.z_scale = 1.0;
	env->transform.rotation_x = 0.0;
	env->transform.rotation_y = 0.0;
	env->transform.rotation_z = 0.0;
	env->transform.translate_x = WIDTH / 2;
	env->transform.translate_y = HEIGHT / 2;
	env->transform.zoom = 1.0;
	env->mlx = NULL;
	env->win = NULL;
	env->image = NULL;
	env->mouse.is_dragging = 0;
	env->mouse.last_x = 0;
	env->mouse.last_y = 0;
	return (env);
}

void	render(t_env *env)
{
	clear_image(env, 0x000000);
	project_and_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->image->img_ptr, 0, 0);
	display_info(env, "Use Scroll to Zoom, Drag to Pan, Arrows to Rotate");
}
