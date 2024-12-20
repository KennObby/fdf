/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oilyine- <oleg.ilyine@student42.luxembour  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:08:58 by oilyine-          #+#    #+#             */
/*   Updated: 2024/12/03 21:26:17 by oilyine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

int	open_file(const char *file_path, t_env *env)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		if (env)
			error_exit("Cannot open file", env);
		return (-1);
	}
	return (fd);
}

void	count_dimensions(t_list *head, int *height, int *max_width)
{
	t_list	*current;
	char	**tokens;
	int		token_count;

	*height = 0;
	*max_width = 0;
	current = head;
	while (current != NULL)
	{
		tokens = ft_split(current->content, ' ');
		token_count = count_tokens(tokens);
		if (token_count > *max_width)
			*max_width = token_count;
		*height = *height + 1;
		ft_free_split(tokens);
		current = current->next;
	}
}
