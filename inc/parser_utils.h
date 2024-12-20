/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:20:51 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 19:54:23 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include "fdf.h"

t_point	create_point(int x, int y, int z, uint32_t color);
t_map	*init_map(int width, int height);
int		count_tokens(char **tokens);
void	append_to_list(t_list **head, t_list *new_node);
void	free_list(t_list *head);
void	populate_map(t_map *map, t_list *head, t_env *env);

#endif
