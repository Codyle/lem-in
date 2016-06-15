/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:05:46 by vgosset           #+#    #+#             */
/*   Updated: 2016/06/15 18:03:54 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	(void)
{
	/*char	*line; affichage, a voir plus tard.
	int		check;
	int		count;

	count = 0;
	check = 0;

	while (get_next_line(0, &line) == 1)
	{
		if (into_struct(line) == -1)
			{
				check = -1;
				break;
			}
			if (into_struct(line) == 0)
			{
				check = 1;
				break;
			}
		count++;
	}
	if (check == 0)
	{
		while (get_next_line(0, &line) == 1)
			ft_putendl(line);
	}
	else if (check == 1)
	{
		while (get_next_line(0, &line) == 1 && count != 0)
		{
			ft_putendl(line);
			count--;
		}
	}
	else
		ft_putendl("error");
}*/



void	parse(t_map)
{
	while (get_next_line(0, &line) == 1)
	{
		if (line[0] == '#' && line[1] != '#')
			continue;
		if (line[0] == '#' && line[1] == '#')
		{
			if (check_com(line) == 1)
				continue;
			else
				break;
		}
		if (is_int(line) == 1)
			continue;
		else
			break;
	}
}

int		is_int(char *line, t_map)
{
	int i;
	int sp;
	int t;

	i = 0;
	while (line[i])
	{
		if (line[i] < '0' || line[i] > '9')
		{
			if (line[i] == ' ')
				sp = 1
			else if (line[i] == '-')
				t = 1;
			else
				break;
		}
		i++;
	}
	if (sp == 1 && t == 1)
		return (0);
	if (line[i])
		return (0);
	else if (sp == 1 && t = 0)
		check_pos(line, t_map);
	else if (sp == 0 && t = 1)
		check_link(line, t_map);
	else
		check_nbrants(line, t_map);
}

int		check_pos(char *line, t_map)
{
	char **tab;

	tab = ft_strsplit(line, ' ');
}
