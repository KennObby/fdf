/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 07:31:21 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/01 07:32:52 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"

t_map	*parse_file(const char *file_path, t_list **lines, t_env *env);
int		open_file(const char *file_path, t_env *env);
t_list	*read_lines(int fd, t_env *env);
void	count_dimensions(t_list *head, int *height, int *max_width);

#endif
