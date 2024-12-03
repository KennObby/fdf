/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:41:18 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 21:06:01 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include "../../inc/parser_utils.h"

t_list	*read_lines(int fd, t_env *env)
{
	t_list	*head;
	t_list	*new_node;
	char	*line;

	head = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new_node = ft_lstnew(line);
		if (new_node == NULL)
			error_exit("Memory allocation failed for list node", env);
		append_to_list(&head, new_node);
	}
	return (head);
}
