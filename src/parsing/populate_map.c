/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:52:28 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 22:07:09 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/**
 * Parses a single point's data and returns a t_point structure.
 * @param token: The string containing z and optional color (e.g., "1,0xFF0000").
 * @param x: x-coordinate.
 * @param y: y-coordinate.
 * @param env: The environment structure for error handling.
 * 
 */
t_point	parse_point(char *token, int x, int y, t_env *env)
{
	t_point	point;
	char	**split_z_color;
	int		z;

	split_z_color = ft_split(token, ' ');
	if (split_z_color == NULL)
		error_exit("Memory allocation failed during split", env);
	if (split_z_color[0])
		z = ft_atoi(split_z_color[0]);
	else
		z = 0;
	if (split_z_color[1])
		point.color = ft_atoi_base(split_z_color[1]);
	else
		point.color = get_color(z);
	point = create_point(x, y, z, color);
	ft_free_split(split_z_color);
	return (point);
}

t_point	handle_null_token(int x, int y)
{
	t_point	point;
	int		z;

	z = 0;
	point = create_point(x, y, z, 0xFFFFFF);
	return (point);
}
/**
 * Populates the map with points, assigning color based 
 * on the map data or z-value
 *
 * @param map: The map structure to populate.
 * @param head: The head of the linked list containing map lines.
 * @param env: The environment structure for error handling.
 *
 */

void	populate_map(t_map *map, t_list *head, t_env *env)
{
	t_list	*current;
	t_point	point;
	char	**tokens;
	int		x;
	int		y;

	y = 0;
	current = head;
	while (current != NULL && y < map->height)
	{
		tokens = ft_split(current->content, ' ');
		if (tokens == NULL)
			error_exit("Memory allocation failed during split", env);
		x = 0;
		while (x < map->width)
		{
			if (tokens[x] != NULL)
				point = parse_point(tokens[x], x, y, env);
			else
				point = handle_null_token(x, y);
			map->points[y][x] = point;
			x++;
		}
		ft_free_split(tokens);
		y++;
		current = current->next;
	}
}
