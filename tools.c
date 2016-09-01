/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:35:11 by vgosset           #+#    #+#             */
/*   Updated: 2016/09/01 17:33:46 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_com(char *line)
{
	int i;

	i = 0;
	if (ft_strcmp(line, "##start") == 0)
	{
		s = 1;
		return (1);
	}
	if (ft_strcmp(line, "##end") == 0)
	{
		e = 1;
		return (1);
	}
	else
		return (0);
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
