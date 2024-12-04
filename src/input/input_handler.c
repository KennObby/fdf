/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 07:05:31 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/04 07:29:51 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	free_ressources(t_env *env)
{
	free_map(env->map);
	free_graphics(env);
	exit(EXIT_SUCCESS);
}

int	handle_destroy(t_env *env)
{
	free_ressources(env);
	return (0);
}

int	handle_keypress(int key, t_env *env)
{
	if (key == KEY_ESC)
		free_ressources(env);
	else if (key == KEY_PLUS)
	{
		env->transform.scale += 1.0;
		render(env);
	}
	else if (key == KEY_MINUS)
	{
		if (env->transform.scale > 1.0)
			env->transform.scale -= 1.0;
		render(env);
	}
	else if (key == KEY_LEFT)
	{
		env->transform.translate_x -= 5.0;
		render(env);
	}
	else if (key == KEY_RIGHT)
	{
		env->transform.translate_x += 5.0;
		render(env);
	}
	else if (key == KEY_UP)
	{
		env->transform.translate_y -= 5.0;
		render(env);
	}
	else if (key == KEY_DOWN)
	{
		env->transform.translate_y += 5.0;
		render(env);
	}
	else if (key == KEY_ROTATE_LEFT)
	{
		env->transform.rotation_z -= 0.1;
		render(env);
	}
	else if (key == KEY_ROTATE_RIGHT)
	{
		env->transform.rotation_z += 0.1;
		render(env);
	}
	return (key);
}

void	setup_event_hooks(t_env *env)
{
	mlx_key_hook(env->win, handle_keypress, env);
	mlx_hook(env->win, 17, 0, handle_destroy, env);
}
