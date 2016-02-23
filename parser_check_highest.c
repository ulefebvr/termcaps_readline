/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_highest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:08:01 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/23 18:45:18 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

t_parse g_parse[] =
{
	{1, check_op_comma, parse_op_comma},
	{2, check_op_parentheses, parse_op_parentheses},
	{0, NULL, NULL}
};

char		*ft_strndup(char *str, int len)
{
	char	*s;

	s = (char * )malloc(sizeof(char) * len + 1);
	ft_bzero(s, sizeof(char) * len + 1);
	ft_memcpy(s, str, len);
	return (s);
}

int			check_hightest(char *cmd, int *type)
{
	int i;

	i = 0;
	while (g_parse[i].check)
	{
		if (g_parse[i].check(cmd))
			return ((*type = i + 1));
		++i;
	}
	return (0);
}

char		**split_on(char *cmd, int pos, int type)
{
	char	**tab;

	tab = NULL;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab = g_parse[type - 1].parse(cmd, pos);
	}
	return (tab);
}
