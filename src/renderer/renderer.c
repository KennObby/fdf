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
#include "../../inc/renderer.h"

int	init_window(t_env *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
	{
		return (-1);
	}
	env->win = mlx_new_window(env->mlx, 1200, 800, "FDF");
	if (env->win == NULL)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		env->mlx = NULL;
		return (-1);
	}
	return (0);
}

t_env	*init_env(t_map *map)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (env == NULL)
		return (NULL);
	env->map = map;
	env->transform.scale = 20.0;
	env->transform.rotation_x = 0.0;
	env->transform.rotation_y = 0.0;
	env->transform.rotation_z = 0.0;
	env->transform.translate_x = 400.0;
	env->transform.translate_y = 300.0;
	env->mlx = NULL;
	env->win = NULL;
	return (env);
}

void	render(t_env *env)
{
	project_and_draw(env);
}
