/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:06:36 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/17 23:12:57 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_HANDLER_H
# define MOUSE_HANDLER_H

# include "fdf.h"

int	handle_scroll(int button, int x, int y, t_env *env);
int	handle_mouse_press(int button, int x, int y, t_env *env);
int	handle_mouse_release(int button, int x, int y, t_env *env);
int	handle_mouse_move(int x, int y, t_env *env);

#endif
