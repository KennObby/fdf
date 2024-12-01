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
t_point	project_point(t_point point, t_transform transform);
void	draw_wireframe(t_env *env);
void	render(t_env *env);

#endif
