/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:39:36 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/16 22:58:00 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

char	*ft_strtok(char *s, const char *delim)
{
	static char		*last;

	if (s == NULL && (s = last) == NULL)
		return (NULL);
	if (ft_strstr(s, delim))
	{
		;
	}
	else
	{
		last = NULL;
		return (s);
	}
	return (NULL);
}
