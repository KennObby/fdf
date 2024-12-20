/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:20:20 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 20:25:46 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <stdint.h>

t_point	create_point(int x, int y, int z, uint32_t color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	point.x_proj = 0.0;
	point.y_proj = 0.0;
	return (point);
}

t_map	*init_map(int width, int height)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = width;
	map->height = height;
	map->points = (t_point **)malloc(sizeof(t_point *) * (height));
	if (map->points == NULL)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		map->points[i] = (t_point *)ft_calloc(width, sizeof(t_point));
		if (map->points[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(map->points[j]);
				j++;
			}
			free(map->points);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

int	count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count] != NULL)
		count++;
	return (count);
}

void	append_to_list(t_list **head, t_list *new_node)
{
	t_list	*current;

	if (head == NULL || new_node == NULL)
		return ;
	else if (*head == NULL)
		*head = new_node;
	else 
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->content);
		free(head);
		head = temp;
	}
}
