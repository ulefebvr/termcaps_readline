/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:57:04 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/18 16:59:24 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_dictionnary.h"

t_parse			*group_nodes(t_parse *list, int key, int value)
{
    t_parse		*tmp;
    t_parse		*tmp2;
    char		ret;

	list->key = value;
    tmp = list->next;
    ft_memdel((void **)&list->value);
    while (tmp)
    {
        if ((ret = (tmp->key != key)))
            list->value = ft_strjoin(list->value, tmp->value);
        tmp2 = tmp->next;
        free(tmp->value);
        free(tmp);
    	tmp = tmp2;
		if (!ret && (list->next = tmp2))
			break;
    }
	return (tmp2);
}

t_parse			*lexer_group(t_parse *cmd, int skey, int ekey, int value)
{
	t_parse	*begin;
	t_parse	*tmp;

	begin = cmd;
	tmp = begin;
	while (tmp)
	{
		if (tmp->key == skey)
		{
			group_nodes(tmp, ekey, value);
		}
		tmp = tmp->next;
	}
	return (begin);
}
