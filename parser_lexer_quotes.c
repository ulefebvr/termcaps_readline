/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:57:04 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/16 17:15:42 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_dictionnary.h"

t_parse			*make_string(t_parse *list/*t_rules*/)
{
    t_parse		*tmp;
    t_parse		*tmp2;
    int			ret;

	list->key = 5;
    tmp = list->next;
    ft_memdel((void **)&list->value);
    while (tmp)
    {
        if ((ret = ft_strcmp(tmp->value, "'")))
            list->value = ft_strjoin(list->value, tmp->value);
        tmp2 = tmp->next;
        free(tmp->value);
        free(tmp);
    	tmp = tmp2;
		if (!ret && (list->next = tmp2))
			break;
    }
	return (list);
}

t_parse		*lexer_quotes(t_parse **cmd/*t_rules*/)
{
	t_parse	*begin;
	t_parse	*tmp;

	begin = *cmd;
	tmp = begin;
	while (tmp)
	{
		if (!ft_strcmp(tmp->value, "'"))
		{
			make_string(tmp);
		}
		tmp = tmp->next;
	}
	return (begin);
}
