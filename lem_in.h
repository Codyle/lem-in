/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:46:17 by vgosset           #+#    #+#             */
/*   Updated: 2016/06/15 18:04:00 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
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
	struct s_nei	*neighbor;
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
void	parse(void);
int		into_struct(char *line);

#endif
