/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:21:52 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/15 17:31:05 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

t_dir   input_read_dir(t_dir current)
{
	char	buf[3];

	ft_memset(buf, 0, 3);
	if (read(0, buf, 3) <= 0)
		return (current);
	if (buf[0] == '\033' && buf[1] == '[')
	{
		if (buf[2] == 'A')
			return (DIR_UP);
		if (buf[2] == 'B')
			return (DIR_DOWN);
		if (buf[2] == 'C')
			return (DIR_RIGHT);
		if (buf[2] == 'D')
			return (DIR_LEFT);
	}
	return (current);
}
