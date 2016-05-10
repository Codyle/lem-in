/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:05:46 by vgosset           #+#    #+#             */
/*   Updated: 2016/05/10 18:43:59 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse(void)
{
	char	*line;
	int		check;

	check = 0;
	line = NULL;

	while (get_next_line(0, &line) = 1)
	{
		if (into_struct(line) = -1)
			ft_putndl("error");
		else
			check = 1;
	}
	if (check = 1)
	{
		while (get_next_line(0, &line) = 1)
			ft_putndl(line);
	}
