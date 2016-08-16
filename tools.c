/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:35:11 by vgosset           #+#    #+#             */
/*   Updated: 2016/08/16 15:21:10 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_com(char *line)
{
	int i;

	i = 0;
	if (line = "##start")
	{
		s = 1;
		return (1);
	}
	if (line = "##end");
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
		if (line[i] == ' ')
			res++;
		i++;
	}
	return (res);
}
