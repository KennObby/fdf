/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 07:38:19 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/01 07:40:06 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"

t_point	*create_point(int x, int y, int z);
t_map	*init_map(int width, int height);
void	error_exit(const char *message);

#endif
