/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_op_parentheses.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:31:19 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/23 18:46:51 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int			check_op_parentheses(char *str)
{
	return ((*str == '(') ? 1 : 0);
}

static char	*subshell_value(char *str)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	while (str[++i] && str[i] != ')')
		;
	if (i > 1)
	{
		value = ft_memalloc(i);
		ft_memcpy(value,  str + 1, i - 1);
	}
	return (value);
}

char		**parse_op_parentheses(char *str, int pos)
{
	char	**tab;

	tab = NULL;
	if ((tab = (char **)malloc(sizeof(char *) * 4)))
	{
		tab[0] = subshell_value(str);
		tab[1] = ft_strdup("()");
		tab[2] = NULL;
	}
	return (tab);
}
