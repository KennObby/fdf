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

# include "types.h"

void	clear_image(t_env *env, uint32_t color);
t_image	*init_image(t_env *env);
t_env	*init_env(t_map *map);
int		init_window(t_env *env);
void	render(t_env *env);

#endif
