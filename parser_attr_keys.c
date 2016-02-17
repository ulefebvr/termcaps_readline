/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_attr_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:44:45 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/17 17:16:21 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_dictionnary.h"

void		parser_attr_keys(t_parse *list, t_parse *func(t_parse *))
{
	t_parse		*tmp;

	tmp = list;
	while (tmp)
	{
		tmp = func(tmp);
		if (tmp)
			tmp = tmp->next;
	}
}
