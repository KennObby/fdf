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
#include <time.h>

/*void	free_ressources(t_env *env)
{
	free_map(env->map);
	free_graphics(env);
	exit(EXIT_SUCCESS);
}

int	handle_destroy(t_env *env)
{
	free_ressources(env);
	return (0);
}*/

int	handle_keypress(int key, t_env *env)
{
	if (key == KEY_ESC)
	{
		free_env(env);
		exit(EXIT_SUCCESS);
		return (0);
	}
	else if (key == KEY_LEFT)
	{
		env->transform.rotation_z -= 0.1;
		display_info(env, "Rotated LEFT");
	}
	else if (key == KEY_RIGHT)
	{
		env->transform.translate_x += 5.0;
		display_info(env, "Rotated RIGHT");
	}
	else if (key == KEY_UP)
	{
		env->transform.translate_y -= 5.0;
		display_info(env, "Rotated UP");
	}
	else if (key == KEY_DOWN)
	{
		env->transform.translate_y += 5.0;
		display_info(env, "Rotated DOWN");
	}
	else if (key == 122)
	{
		env->transform.rotation_z -= 0.1;
		display_info(env, "Rotated Y+");
	}
	else if (key == 120)
	{
		env->transform.rotation_z += 0.1;
		display_info(env, "Rotated Y-");
	}
	else
		return (0);
	render(env);
	return (0);
}

void	setup_event_hooks(t_env *env)
{
	mlx_hook(env->win, 4, 0, handle_scroll, env);
	mlx_hook(env->win, 5, 0, handle_mouse_release, env);
	mlx_hook(env->win, 6, 0, handle_mouse_move, env);
	mlx_hook(env->win, 1, 0, handle_mouse_press, env);
	mlx_hook(env->win, 2, 1L<<0, handle_keypress, env);
}
