/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoshabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:56:24 by mmoshabe          #+#    #+#             */
/*   Updated: 2020/01/19 16:10:02 by mmoshabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	convert(char *row)
{
	int		i;
	char	*col;

	i = 0;
	col = (char*)malloc(sizeof(char) * 10);
	while (i < 10)
	{
		row[i] = col[i];
		i++;
	}
	col[i] = '\0';
	return (col);
}
