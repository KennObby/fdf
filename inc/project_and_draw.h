/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_and_draw.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:11:29 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 18:14:33 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_AND_DRAW_H
# define PROJECT_AND_DRAW_H

# include "fdf.h"
# include "types.h"

t_range	get_z_range(t_map *map);
double	compute_scale(t_range range, t_env *env);
void	project_and_draw(t_env *env);
void	center_map(t_env *env, t_map *map);
void	draw_neighbors(t_env *env, t_point *point);

#endif
