/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:35:11 by vgosset           #+#    #+#             */
/*   Updated: 2016/09/06 12:01:35 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_com(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		s = 1;
	if (ft_strcmp(line, "##end") == 0)
		e = 1;
}

int		find_type(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			return (2);
		if (line[i] == '-')
			return (3);
		i++;
	}
	if (ft_atoi(line) == 0)
		return (0);
	else
		return (1);
}

int		check_nbrc(char *line, char c)
{
	int i;
	int	res;

	res = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			res++;
		i++;
	}
	return (res);
}

t_map	*init_map(t_map *map)
{
	map = (t_map *)malloc(sizeof(*map));
	map->ant = 0;
	map->room = 0;
	return (map);
}

t_room	*init_room(t_room *room)
{
	room = (t_room *)malloc(sizeof(*room));
	room->next = NULL;
	room->ant = 0;
	room->x = 0;
	room->y = 0;
	room->nbr_nei = 0;
	return (room);
}
