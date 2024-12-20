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

# include "types.h"
# include "fdf.h"

void	display_info(t_env *env, char *info);
void	error_exit(const char *message, t_env *env);
void	ft_free_split(char **split);

#endif
