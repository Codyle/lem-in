/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:46:17 by vgosset           #+#    #+#             */
/*   Updated: 2016/09/05 18:33:04 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "Lib/includes/libft.h"
# include "Lib/includes/get_next_line.h"
# include <fcntl.h>
typedef struct		s_nei
{
	char			*name;
	struct s_nei	*next;
}					t_nei;

typedef struct		s_room
{
	int				ant;
	char			*name;
	int				x;
	int				y;
	int				nbr_nei;
	struct s_nei	*nei;
	struct s_room	*next;
}					t_room;

typedef struct		s_map
{
	struct s_room	*start;
	struct s_room	*end;
	struct s_room	*top;
	int				ant;
	int				room;
}					t_map;

int s;
int e;

int		ft_strchr2(char *s, char c);
void	parse(t_map *map, t_room *room);
int		into_struct(char *line);
void	check_com(char *line);
int		find_type(char *line);
int		check_nbrc(char *line, char c);
t_map	*init_map(t_map *map);
t_room	*init_room(t_room *room);

#endif
