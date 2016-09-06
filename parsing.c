/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:05:46 by vgosset           #+#    #+#             */
/*   Updated: 2016/09/06 12:00:04 by vgosset          ###   ########.fr       */
	/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "Lib/includes/libft.h"

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
		if (!map)
			map = init_map(map);
		if (map->ant == 0)
				map->ant = ft_atoi(line);
	return (1);
}

static int		check_link(char *line, t_map *map)
{
	struct s_room *tmp;
	char **tab;
	struct s_nei *nei;

	nei = NULL;
	if (!map)
		map = init_map(map);
	tmp = map->start;
	tab = ft_strsplit(line, '-');
	while (tmp->next && ft_strcmp(tmp->name, tab[0]) != 0) //seg
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
	int i;

	i = 0;
	if (!map)
		map = init_map(map);
	if (!room)
		room = init_room(room);
	while (room->next != NULL)
		room = room->next;
	if (check_nbrc(line, ' ') != 2)
		return (0);
	tab = ft_strsplit(line, ' ');
	room->name = tab[0];
	if (*tab[1] < '0' || *tab[1] > '9')
		return (0);
	else
		room->x = ft_atoi(tab[1]);
	if (*tab[2] < '0' || *tab[2] > '9')
		return (0);
	else
		room->y = ft_atoi(tab[2]);
	if (s == 1)
		map->start = room;
	if (s == 1)
		map->end = room;
	return (1);
}


void	parse(t_map *map, t_room *room)
{
	char	*line;
	int	i;

	i=1;
	line = NULL;
	while (get_next_line(0,  &line) > 0)
	{
		ft_printf("Ligne  %d : ", i);
		ft_putstr(line);
		ft_printf("\n");
		i++;
		if (line[0] == '#' && line[1] == '#')
			check_com(line);
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
		else if (find_type(line) == 3)
		{
			if (check_link(line, map) == 0)
				break;
		}
		free(line);
	}
}

