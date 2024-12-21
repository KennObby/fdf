/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:27:07 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/21 19:30:02 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POPULATE_H
# define POPULATE_H

# include "fdf.h"
# include "types.h"

t_point	handle_null_token(int x, int y);
t_point	parse_point(char *token, int x, int y, t_env *env);
void	populate_map(t_map *map, t_list *head, t_env *env);

#endif
