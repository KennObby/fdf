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

# include "types.h"

int		handle_keypress(int key, t_env *env);
int		handle_mouse(int button, int x, int y, t_env *env);
void	setup_event_hooks(t_env *env);

# define KEY_ESC 65307
# define KEY_PLUS 52 
# define KEY_MINUS 78
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65307
# define KEY_ROTATE_LEFT 0 
# define KEY_ROTATE_RIGHT 2

#endif
