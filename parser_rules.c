/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:02:59 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/18 23:59:41 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_dictionnary.h"

t_parse		*rules_backslash(t_parse *node)
{
	if (!ft_strcmp("\\", node->value) && !node->key)
	{
		node->key = BSLH;
		if (node->next)
			node->next->key = CHR;
		node = node->next;
	}
	return (node);
}

t_parse		*rules_quotes(t_parse *node)
{
	static int	squote;
	static int	dquote;

	if (!ft_strcmp("\'", node->value) && node->key != CHR)
	{
		node->key = (dquote % 2) ? CHR : SQTE;
		squote += (dquote % 2) ? 0 : 1;
		squote = (squote == 2) ? 0 : squote;
		node = node->next;
	}
	else if (!ft_strcmp("\"", node->value) && node->key != CHR)
	{
		node->key = (squote % 2) ? CHR : DQTE;
		dquote += (squote % 2) ? 0 : 1;
		dquote = (dquote == 2) ? 0 : dquote;
		node = node->next;
	}
	return (node);
}

t_parse		*rules_priority(t_parse *node)
{
	if (node->key != CHR)
	{
		if (!ft_strcmp("{", node->value) || !ft_strcmp("}", node->value))
			node->key = ACLD;
		else if (!ft_strcmp("(", node->value) || !ft_strcmp(")", node->value))
			node->key = PRTH;
		else if (!ft_strcmp("[", node->value) || !ft_strcmp("]", node->value))
			node->key = CRHT;
	}
	return (node);
}
