/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:05:46 by vgosset           #+#    #+#             */
/*   Updated: 2016/05/11 15:35:25 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse(void)
{
	char	*line;
	int		check;
	int		count;

	count = 0;
	check = 0;

	while (get_next_line(0, &line) == 1)
	{
		if (into_struct(line) == -1)
		{
			check = 1;
			break;
		}
		if (into_struct(line) == 0)
		{
			check = 2;
			break;
		}
		count++;
	}
	if (check == 0)
	{
		while (get_next_line(0, &line) == 1)
			ft_putendl(line);
	}
	if (check == 2)
	{
		while (get_next_line(0, &line) == 1 && count != 0)
		{
			ft_putendl(line);
			count--;
		}
	}
	else
		ft_putendl("error");
}
