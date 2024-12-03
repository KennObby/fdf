/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 07:32:59 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/01 07:35:27 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "fdf.h"

t_env	*init_graphics(t_map *map);
void	render(t_env *env);
void	project_and_draw(t_env *env);
void	draw_line(t_env *env, t_point p1, t_point p2);
void	free_graphics(t_env *env);

#endif
