/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:32:59 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/02 15:24:26 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	free_map(t_map *map)
{
	int	y;

	if (map == NULL)
		return ;
	y = 0;
	while (y < map->height)
	{
		if (map->points[y] != NULL)
			free(map->points[y]);
		y++;
	}
	free(map->points);
	free(map);
}

t_map	*parse_file(const char *file_path)
{
	int		fd;
	t_list	*lines;
	t_map	*map;
	int		height;
	int		max_width;

	fd = open_file(file_path, env);
	lines = read_lines(fd, env);
	close(fd);
	count_dimensions(lines, &height, &max_width);
	map = init_map(max_width, height);
	if (map == NULL)
		error_exit("Memory allocation failed for map", env);
	populate_map(map, lines, env);
	free_list(lines);
	return (map);
}
