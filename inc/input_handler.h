/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 07:36:12 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/01 07:37:56 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H

# include "fdf.h"

int		handle_keypress(int key, t_env *env);
int		handle_mouse(int button, int x, int y, t_env *env);
void	setup_event_hooks(t_env *env);

typedef enum e_keys
{
	KEY_ESC = 53,
	KEY_PLUS = 69,
	KEY_MINUS = 78,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
}			t_keys;

#endif
