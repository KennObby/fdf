/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:14:22 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/17 18:15:16 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "fdf.h"
# include "types.h"

void	destroy_image(t_env *env);
void	destroy_window(t_env *env);
void	destroy_mlx(t_env *env);
void	free_map(t_map *map);
void	free_env(t_env *env);

#endif
