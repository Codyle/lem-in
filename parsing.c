/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:05:46 by vgosset           #+#    #+#             */
/*   Updated: 2016/08/17 16:13:07 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*void	(void)
{
	char	*line; affichage, a voir plus tard.
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




static int		check_ants(char *line, t_map *map)
{
	if (ft_atoi(line) == 0)
		return (0);
	else
		map->ant = ft_atoi(line);
	return (1);
}

static int		check_link(char *line, t_room *room, t_map *map)
{
	struct s_room *tmp;
	char **tab;
	struct s_nei *nei;

	tmp = map->start;
	tab = ft_strsplit(line, '-');
	while (tmp->next && ft_strcmp(tmp->name, tab[0]) != 0)
		tmp = tmp->next;
	if (ft_strcmp(tmp->name, tab[0]) == 0)
	{
		while (nei->next)
			nei = nei->next;
		nei->name = tab[1];
		return (1);
	}
	return (0);
}

static int		check_room(char *line, t_map *map, t_room *room)
{
	char **tab;

	while (room->next)
		room = room->next;
	if (check_nbrc(line, ' ') != 2)
		return (0);
	tab = ft_strsplit(line, ' ');
	room->name = tab[0];
	if (ft_atoi(tab[1]) == 0)
		return (0);
	else
		room->x = ft_atoi(tab[1]);
	if (ft_atoi(tab[2]) == 0)
		return (0);
	else
		room->y = ft_atoi(tab[2]);
	if (s == 1)
		map->start = room;
	if (s == 1)
		map->end = room;
	return (1);
}


void	parse(char *line, t_map *map, t_room *room)
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
		if (find_type(line) == 1)
		{
			if (check_ants(line, map) == 0)
				break;
		}
		else if (find_type(line) == 2)
		{
			if (check_room(line, map, room) == 0)
				break;
		}
		else
		{
			if (check_link(line, room, map) == 0)
				break;
		}
	}
}

