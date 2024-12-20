/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_point.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:56:11 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/17 22:00:41 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_POINT_H
# define PROJECT_POINT_H

# include "fdf.h"
# include "types.h"

void	compute_sincos(t_transform *transform);
void	apply_rotation(t_point *point, t_transform *transform);
t_point	project_iso(t_env *env, t_point *point);
void	apply_scaling_translation(t_point *point, t_transform *transform);
void	project_point(t_env *env, t_point *point);
#endif
