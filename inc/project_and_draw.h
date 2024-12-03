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

void	project_and_draw(int *env);
void	project_point(t_env *env, t_point *point);
void	draw_neighbors(t_env *env, t_point *point);

#endif
