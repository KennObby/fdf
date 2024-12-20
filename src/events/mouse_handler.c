/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:05:58 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/17 23:38:42 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

int	handle_mouse_press(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		env->mouse.is_dragging = 1;
		env->mouse.last_x = x;
		env->mouse.last_y = y;
		display_info(env, "Panning Started");
	}
	return (0);
}

int	handle_mouse_release(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		env->mouse.is_dragging = 0;
		display_info(env, "Panning Ended");
	}
	return (0);
}

int	handle_mouse_move(int x, int y, t_env *env)
{
	int	delta_x;
	int	delta_y;

	if (env->mouse.is_dragging)
	{
		delta_x = env->mouse.last_x;
		delta_y = env->mouse.last_y;
		env->transform.translate_x += delta_x * 0.5;
		env->transform.translate_y += delta_y * 0.5;
		env->mouse.last_x = x;
		env->mouse.last_y = y;
		render(env);
	}
	return (0);
}

int	handle_scroll(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		env->transform.scale *= 1.05;
		render(env);
		display_info(env, "Zoomed IN");
	}
	else if (button == 5)
	{
		env->transform.scale /= 1.05;
		render(env);
		display_info(env, "Zoomed OUT");
	}
	return (0);
}
